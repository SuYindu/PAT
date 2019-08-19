#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int ROOT = 0;

struct TreeNode {
    int key;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
};

int size(TreeNode *node) {
    if (node == nullptr) return 0;
    return 1 + size(node->left) + size(node->right);
}

typedef vector<int>::iterator Iterator;

void fill_keys(TreeNode *node, Iterator begin, Iterator end) {
    if (node == nullptr) return;
    int n = size(node->left);
    node->key = begin[n];
    fill_keys(node->left, begin, begin + n - 1);
    fill_keys(node->right, begin + n + 1, end);
}

void build(vector<TreeNode> &nodes, vector<int> &keys) {
    sort(keys.begin(), keys.end());
    fill_keys(&nodes[ROOT], keys.begin(), keys.end());
}

void bfs(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        if (temp->left  != nullptr) q.push(temp->left );
        if (temp->right != nullptr) q.push(temp->right);
        cout << temp->key << (!q.empty() ? ' ' : '\n');
    }
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> nodes(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l != -1) nodes[i].left  = &nodes[l];
        if (r != -1) nodes[i].right = &nodes[r];
    }
    vector<int> keys(n);
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    build(nodes, keys);
    bfs(&nodes[ROOT]);
    return 0;
}