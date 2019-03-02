#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left  = NULL;
    TreeNode *right = NULL;
};

void InvertTree(TreeNode *node) {
    if (node == NULL) return;
    swap(node->left, node->right);
    InvertTree(node->left);
    InvertTree(node->right);
}

void LevelOrder(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        if (temp != root) cout << ' ';
        cout << temp->key;
        if (temp->left)  q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

void InOrder(TreeNode *node, vector<int> &inorder) {
    if (node == NULL) return;
    InOrder(node->left,  inorder);
    inorder.push_back(node->key);
    InOrder(node->right, inorder);
}

void InOrder(TreeNode *root) {
    vector<int> inorder;
    InOrder(root, inorder);
    for (int i = 0; i < inorder.size(); i++)
        cout << inorder[i] << (i < inorder.size() - 1 ? ' ' : '\n');
}

TreeNode* FindRoot(vector<TreeNode> &nodes) {
    const int n = nodes.size();
    vector<bool> is_root(n, true);
    for (auto node : nodes) {
        if (node.left ) is_root[node.left ->key] = false;
        if (node.right) is_root[node.right->key] = false;
    }
    for (int i = 0; i < n; i++)
        if (is_root[i]) return &nodes[i];
    return nullptr;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].key = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") nodes[i].left  = &nodes[stoi(l)];
        if (r != "-") nodes[i].right = &nodes[stoi(r)];
    }
    TreeNode *root = FindRoot(nodes);
    InvertTree(root);
    LevelOrder(root);
    InOrder(root);
    return 0;
}