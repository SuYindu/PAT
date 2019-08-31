#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key, level;
    TreeNode *lchild = nullptr;
    TreeNode *rchild = nullptr;

    TreeNode(int key) : key(key) {}
};

TreeNode* build(int *in, int *post, int n) {
    if (n <= 0) return nullptr;
    TreeNode *node = new TreeNode(post[n - 1]);
    int i = 0;
    while (i < n && in[i] != node->key) i++;
    node->lchild = build(in, post, i);
    node->rchild = build(in + i + 1, post + i, n - i - 1);
    return node;
}

void zigzag(TreeNode *root, int n) {
    vector<int> order[n];
    queue<TreeNode*> q;
    root->level = 0;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front(); q.pop();
        if (!node) continue;
        order[node->level].push_back(node->key);
        if (node->lchild) node->lchild->level = node->level + 1;
        if (node->rchild) node->rchild->level = node->level + 1;
        q.push(node->lchild);
        q.push(node->rchild);
    }
    printf("%d", root->key);
    for (int i = 1; i < n; i++) {
        auto print = [](int x) { printf(" %d", x); };
        if (i & 1) for_each(order[i].begin(),  order[i].end(),  print);
        else       for_each(order[i].rbegin(), order[i].rend(), print);
    }
}

int main() {
    int n;
    cin >> n;
    int in[n], post[n];
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    TreeNode *root = build(in, post, n);
    zigzag(root, n);
    return 0;
}