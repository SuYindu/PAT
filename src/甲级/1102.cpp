#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
};

void invert(TreeNode *node) {
    if (node == nullptr) return;
    invert(node->left);
    invert(node->right);
    swap(node->left, node->right);
}

void bfs(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        if (temp->left)  q.push(temp->left);
        if (temp->right) q.push(temp->right);
        cout << temp->key << (!q.empty() ? ' ' : '\n');
    }
}

void print(TreeNode *node) {
    static bool flag = false;
    if (flag) cout << ' ';
    cout << node->key;
    flag = true;
}

void in_order(TreeNode *node) {
    if (node == nullptr) return;

    in_order(node->left);
    print(node);
    in_order(node->right);
}

TreeNode* find_root(vector<TreeNode> &nodes) {
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
    TreeNode *root = find_root(nodes);
    invert(root);
    bfs(root);
    in_order(root);
    return 0;
}