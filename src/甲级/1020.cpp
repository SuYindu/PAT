#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *create_tree(int *post, int *in, int len) {
    if (len <= 0) return nullptr;
    int i = 0;
    TreeNode *root = new TreeNode{post[len - 1], nullptr, nullptr};
    while (i < len && in[i] != root->key) i++;
    root->left  = create_tree(post, in, i);
    root->right = create_tree(post + i, in + i + 1, len - i - 1);
    return root;
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

int main() {
    int n;
    cin >> n;
    int post[n], in[n];
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    bfs(create_tree(post, in, n));
    return 0;
}