#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left, *right;

    TreeNode(int key) : key(key), left(NULL), right(NULL) {}
};

TreeNode* ConstructTree(int *preorder, int *inorder, int n) {
    if (n <= 0) return NULL;
    
    int i;
    TreeNode *root = new TreeNode(*preorder);
    for (i = 0; i < n; i++)
        if (inorder[i] == root->key) break;
    root->left = ConstructTree(preorder + 1, inorder, i);
    root->right = ConstructTree(preorder + i + 1, inorder + i + 1, n - i - 1);
    return root;
}

void PostorderTraversal(TreeNode *root, vector<int> &postorder) {
    if (root == NULL) return;

    PostorderTraversal(root->left, postorder);
    PostorderTraversal(root->right, postorder);
    postorder.push_back(root->key);
}

int main() {
    int n;
    cin >> n;
    int *preorder = new int[n];
    int *inorder = new int[n];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode *root = ConstructTree(preorder, inorder, n);
    vector<int> postorder;
    PostorderTraversal(root, postorder);
    cout << postorder.front() << endl;
    return 0;
}