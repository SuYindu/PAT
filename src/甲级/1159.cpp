#include <iostream>
#include <string>
#include <map>
using namespace std;

struct TreeNode {
    int key, level;
    TreeNode *parent;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(int key) : key(key) { parent = lchild = rchild = nullptr; }
};

map<int, TreeNode*> nodes;

struct Tree {
    TreeNode *root;
    bool is_full = true;

    TreeNode* build(int *in, int *post, int n) {
        if (n <= 0) return nullptr;

        int i;
        TreeNode *node = new TreeNode(post[n - 1]);
        for (i = 0; i < n && in[i] != node->key; i++);
        node->lchild = build(in, post, i);
        node->rchild = build(in + i + 1, post + i, n - i - 1);
        if (node->lchild) node->lchild->parent = node;
        if (node->rchild) node->rchild->parent = node;
        return nodes[node->key] = node;
    }

    void dfs(TreeNode *node) {
        if (node == nullptr) return;
        if (node->parent) node->level = node->parent->level + 1;
        if (node->lchild && !node->rchild) is_full = false;
        if (!node->lchild && node->rchild) is_full = false;
        dfs(node->lchild);
        dfs(node->rchild);
    }

    Tree(int *in, int *post, int n) {
        root = build(in, post, n);
        root->level = 0;
        dfs(root);
    }
};

int main() {
    int n, m;
    cin >> n;
    int in[n], post[n];
    for (int i = 0; i < n; i++) cin >> post[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    Tree tree(in, post, n);
    cin >> m; getchar();
    while (m--) {
        bool flag;
        int a, b;
        string stat;
        getline(cin, stat);
        if (stat.find("root") != string::npos) {
            sscanf(stat.c_str(), "%d is the root", &a);
            flag = (tree.root->key == a);
        } else if (stat.find("siblings") != string::npos) {
            sscanf(stat.c_str(), "%d and %d are siblings", &a, &b);
            flag = (nodes[a]->parent == nodes[b]->parent);
        } else if (stat.find("parent") != string::npos) {
            sscanf(stat.c_str(), "%d is the parent of %d", &a, &b);
            flag = (nodes[b]->parent == nodes[a]);
        } else if (stat.find("left") != string::npos) {
            sscanf(stat.c_str(), "%d is the left child of %d", &a, &b);
            flag = (nodes[b]->lchild == nodes[a]);
        } else if (stat.find("right") != string::npos) {
            sscanf(stat.c_str(), "%d is the right child of %d", &a, &b);
            flag = (nodes[b]->rchild == nodes[a]);
        } else if (stat.find("level") != string::npos) {
            sscanf(stat.c_str(), "%d and %d are on the same level", &a, &b);
            flag = (nodes[a]->level == nodes[b]->level);
        } else {
            flag = tree.is_full;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}