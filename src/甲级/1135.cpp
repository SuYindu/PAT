// 注意每次迭代之后再次初始化全局变量

#include <iostream>
#include <vector>
using namespace std;

enum Color {RED, BLACK};

struct TreeNode {
    int key;
    Color color;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : left(NULL), right(NULL) {
        this->key = key > 0 ? key : -key;
        color = key > 0 ? BLACK : RED;
    }
};

void BlackDepth(TreeNode *root, int count, vector<int> &black_depth) {
    if (root == NULL) { black_depth.push_back(++count); return; }

    if (root->color == BLACK) count++;
    BlackDepth(root->left, count, black_depth);
    BlackDepth(root->right, count, black_depth);
}

bool HasTwoBlackChildren(TreeNode *root) {
    if (root == NULL) return true;

    if (root->color == RED)
        if ((root->left && root->left->color == RED) 
        || (root->right && root->right->color == RED))
            return false;

    return HasTwoBlackChildren(root->left)
        && HasTwoBlackChildren(root->right);
}

bool IsRedBlackTree(TreeNode *root) {
    if (root->color != BLACK) return false;
    if (!HasTwoBlackChildren(root->left)) return false;
    if (!HasTwoBlackChildren(root->right)) return false;
    vector<int> black_depth;
    BlackDepth(root, 0, black_depth);
    for (auto depth : black_depth)
        if (depth != black_depth.front())
            return false;
    return true;
}

TreeNode* ConstructTree(int *preorder, int n) {
    if (n <= 0) return NULL;

    int i;
    TreeNode *root = new TreeNode(*preorder);
    for (i = 1; i < n; i++)
        if (abs(preorder[i]) >= root->key) break;
    root->left = ConstructTree(preorder + 1, i - 1);
    root->right = ConstructTree(preorder + i, n - i);
    return root;
}

int main() {
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        int *preorder = new int[n];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        TreeNode *root = ConstructTree(preorder, n);
        cout << (IsRedBlackTree(root) ? "Yes" : "No") << endl;
    }
    return 0;
}