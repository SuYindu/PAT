#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(int x) : key(x), left(NULL), right(NULL), parent(NULL) {}
};

map<int, TreeNode*> key2node;

bool FindKeys(int u, int v) {
    switch(key2node.count(u) * 2 + key2node.count(v)) {
    case 0:
        printf("ERROR: %d and %d are not found.\n", u, v); return false;
    case 1:
        printf("ERROR: %d is not found.\n", u); return false;
    case 2:
        printf("ERROR: %d is not found.\n", v); return false;
    case 3:
        return true;
    }
}

void FindLCA(int u, int v, vector<int> &v1, vector<int> &v2) {
    sort(v1.begin(), v1.end());
    for (auto key : v2) {
        if (binary_search(v1.begin(), v1.end(), key)) {
            printf("LCA of %d and %d is %d.\n", u, v, key);
            return;
        }
    }
}

void FindLCA(int u, int v, TreeNode *root) {
    if (!FindKeys(u, v)) return;
    vector<int> ancestors_u;
    vector<int> ancestors_v;
    TreeNode *temp = key2node[u];
    while (temp != NULL) {
        ancestors_u.push_back(temp->key);
        temp = temp->parent;
    }
    temp = key2node[v];
    while (temp != NULL) {
        ancestors_v.push_back(temp->key);
        temp = temp->parent;
    }
    for (auto key : ancestors_u)
        if (key == v) { printf("%d is an ancestor of %d.\n", v, u); return; }
    for (auto key : ancestors_v)
        if (key == u) { printf("%d is an ancestor of %d.\n", u, v); return; }
    if (ancestors_u.size() > ancestors_v.size())
        FindLCA(u, v, ancestors_u, ancestors_v);
    else
        FindLCA(u, v, ancestors_v, ancestors_u);
}

TreeNode* ConstructTree(int *preorder, int *inorder, int n) {
    int i;
    if (n <= 0) return NULL;
    int root_key = *preorder;
    TreeNode *root = new TreeNode(root_key);
    for (i = 0; i < n; i++)
        if (inorder[i] == root_key) break;
    root->left = ConstructTree(preorder + 1, inorder, i);
    root->right = ConstructTree(preorder + i + 1, inorder + i + 1, n - i - 1);
    if (root->left) root->left->parent = root;
    if (root->right) root->right->parent = root;
    key2node.insert({root->key, root});
    return root;
}

int main() {
    int m, n;
    cin >> m >> n;
    int *inorder, *preorder;
    inorder = new int[n], preorder = new int[n];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    TreeNode *root = ConstructTree(preorder, inorder, n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        FindLCA(u, v, root);
    }
    return 0;
}