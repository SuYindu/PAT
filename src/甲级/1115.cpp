#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : key(key), left(NULL), right(NULL) {}
};

struct BST {
    TreeNode *root;
    vector<int> count;
    int max_depth;

    BST(int n) : root(NULL), count(n, 0), max_depth(-1) {}

    TreeNode* Insert(int key, TreeNode *node) {
        if (node == NULL) return new TreeNode(key);
        if (key <= node->key)
            node->left  = Insert(key, node->left);
        else if (key > node->key)
            node->right = Insert(key, node->right);
        return node;
    }

    void Insert(int key) {
        root = Insert(key, root);
    }

    void DFS(TreeNode *node, int depth) {
        if (node == NULL) { max_depth = max(depth - 1, max_depth); return; }
        count[depth]++;
        DFS(node->left,  depth + 1);
        DFS(node->right, depth + 1);
    }

    void Output() {
        DFS(root, 0);
        int n1 = count[max_depth], n2 = count[max_depth - 1];
        printf("%d + %d = %d\n", n1, n2, n1 + n2);
    }
};

int main() {
    int n;
    cin >> n;
    BST tree(n);
    while (n--) { int key; cin >> key; tree.Insert(key); }
    tree.Output();
    return 0;
}