#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    vector<TreeNode*> children;
};

#define MAX_N 105
vector<TreeNode> nodes(MAX_N);
vector<int> count(MAX_N);

void dfs(TreeNode *node, int level) {
    if (node == nullptr) return;
    count[level]++;
    for (auto child : node->children)
        dfs(child, level + 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int id, k, child;
        cin >> id >> k;
        while (k--) {
            cin >> child;
            nodes[id].children.push_back(&nodes[child]);
        }
    }
    TreeNode *root = &nodes[1];
    dfs(root, 1);
    int max = 1;
    for (int i = 1; i <= n; i++)
        if (count[i] > count[max]) max = i;
    printf("%d %d\n", count[max], max);
    return 0;
}