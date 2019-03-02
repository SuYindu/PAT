#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(int key) : key(key), left(NULL), right(NULL), parent(NULL) {}
};

unordered_map<int, TreeNode*> key2node;

void FindLCA(int u, int v, vector<int> &v1, vector<int> v2) {
    sort(v1.begin(), v1.end());
    for (auto key : v2) {
        if (binary_search(v1.begin(), v1.end(), key)) {
            printf("LCA of %d and %d is %d.\n", u, v, key);
            return;
        }
    }
}

void FindLCA(int u, int v) {
    TreeNode *temp;
    vector<int> ancestors_u;
    vector<int> ancestors_v;
    temp = key2node[u];
    while (temp) {
        ancestors_u.push_back(temp->key);
        temp = temp->parent;
    }
    temp = key2node[v];
    while (temp) {
        ancestors_v.push_back(temp->key);
        temp = temp->parent;
    }
    for (auto key : ancestors_u)
        if (key == v) { printf("%d is an ancestor of %d.\n", v, u); return; }
    for (auto key : ancestors_v)
        if (key == u) { printf("%d is an ancestor of %d.\n", u, v); return; }
    // 排序大数组用于二分搜索以加速
    if (ancestors_u.size() > ancestors_v.size())
        FindLCA(u, v, ancestors_u, ancestors_v);
    else
        FindLCA(u, v, ancestors_v, ancestors_u);
}

TreeNode* ConstructTree(int *preorder, int n) {
    if (n <= 0) return NULL;

    int i;
    TreeNode *root = new TreeNode(*preorder);
    for (i = 1; i < n; i++)
        if (preorder[i] > root->key) break;
    root->left = ConstructTree(preorder + 1, i - 1);
    root->right = ConstructTree(preorder + i, n - i);
    if (root->left) root->left->parent = root;
    if (root->right) root->right->parent = root;
    key2node[root->key] = root;
    return root;
}

int main() {
    int m, n;
    cin >> m >> n;
    int *preorder = new int[n];
    unordered_set<int> keys;
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
        keys.insert(preorder[i]);
    }
    ConstructTree(preorder, n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        switch(keys.count(u) * 2 + keys.count(v)) {
            case 3: FindLCA(u, v); break;
            case 2: printf("ERROR: %d is not found.\n", v); break;
            case 1: printf("ERROR: %d is not found.\n", u); break;
            case 0: printf("ERROR: %d and %d are not found.\n", u, v); break;
        }
    }
    return 0;
}