#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int level;
    vector<TreeNode*> children;
};

void Traversal(TreeNode *node) {
    if (node == NULL) return;
    for (auto child : node->children) {
        child->level = node->level + 1;
        Traversal(child);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<TreeNode> nodes(n + 1);
    while (m--) {
        int id, k;
        cin >> id >> k;
        nodes[id].children.resize(k);
        for (int i = 0; i < k; i++) {
            int child;
            cin >> child;
            nodes[id].children[i] = &nodes[child];
        }
    }
    TreeNode *root = &nodes[1];
    root->level = 1;
    Traversal(root);
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; i++)
        count[nodes[i].level]++;
    int max = 0;
    for (int i = 1; i <= n; i++)
        if (count[i] > count[max]) max = i;
    printf("%d %d\n", count[max], max);
    return 0;
}