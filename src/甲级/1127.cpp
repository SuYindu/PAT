#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key, level;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(int key) : key(key), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* ConstructTree(int *inorder, int *postorder, int n) {
    if (n <= 0) return NULL;

    int i = 0;
    TreeNode *root = new TreeNode(postorder[n - 1]);
    while (i < n && inorder[i] != root->key) i++;
    root->left = ConstructTree(inorder, postorder, i);
    root->right = ConstructTree(inorder + i + 1, postorder + i, n - i - 1);
    if (root->left)  root->left->parent  = root;
    if (root->right) root->right->parent = root;
    return root;
}

int max_level = 0;

void Traversal(TreeNode *node) {
    if (node == NULL) return;
    if (node->parent) node->level = node->parent->level + 1;
    max_level = max(max_level, node->level);
    Traversal(node->left);
    Traversal(node->right);
}

void ZigZag(TreeNode *root) {
    root->level = 0;
    Traversal(root);
    vector<int> v[max_level + 1];

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        v[temp->level].push_back(temp->key);
        if (temp->left  != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }

    printf("%d", root->key);
    for (int i = 1; i <= max_level; i++) {
        auto Print = [](int x) { printf(" %d", x); };
        if (i % 2) for_each(v[i].begin(),  v[i].end(),  Print);
        else       for_each(v[i].rbegin(), v[i].rend(), Print);
    }
    printf("\n");
}

int main() {
    int n;
    cin >> n;
    int *inorder   = new int[n];
    int *postorder = new int[n];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    ZigZag(ConstructTree(inorder, postorder, n));
    return 0;
}