#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int key, level;
    TreeNode *lchild = nullptr;
    TreeNode *rchild = nullptr;
    TreeNode *parent = nullptr;

    TreeNode(int key, int level) : key(key), level(level) {}
};

map<int, TreeNode*> nodes;

TreeNode* build(int *in, int *pre, int n, int level) {
    if (n <= 0) return nullptr;
    TreeNode *node = new TreeNode(*pre, level);
    int i;
    for (i = 0; i < n && in[i] != node->key; i++);
    node->lchild = build(in, pre + 1, i, level + 1);
    node->rchild = build(in + i + 1, pre + i + 1, n - i - 1, level + 1);
    if (node->lchild) node->lchild->parent = node;
    if (node->rchild) node->rchild->parent = node;
    return nodes[node->key] = node;
}

int main() {
    int m, n;
    cin >> m >> n;
    int in[n], pre[n];
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> pre[i];
    TreeNode *root = build(in, pre, n, 0);
    while (m--) {
        int v, w;
        cin >> v >> w;
        TreeNode *node1 = nodes[v], *node2 = nodes[w];
        if (!node1 && !node2) {
            printf("ERROR: %d and %d are not found.\n", v, w);
        } else if (node1 && !node2) {
            printf("ERROR: %d is not found.\n", w);
        } else if (!node1 && node2) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            bool flag = node2->level < node1->level;
            if (node2->level < node1->level) swap(node1, node2);
            while (node1->level < node2->level)
                node2 = node2->parent;
            if (node1 == node2) { // 测试点 2：两节点相同（题目没有说明）
                printf("%d is an ancestor of %d.\n", node1->key, flag ? v : w);
            } else {
                while (node1 != node2) {
                    node1 = node1->parent;
                    node2 = node2->parent;
                }
                printf("LCA of %d and %d is %d.\n", v, w, node1->key);
            }
        }
    }
    return 0;
}