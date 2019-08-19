#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct Tree {
    TreeNode *root = nullptr;

    Tree(vector<int> keys) { for (auto key : keys) insert(key); }

    void insert(int key, TreeNode *&node) {
        if (node == nullptr)      node = new TreeNode(key);
        else if (key < node->key) insert(key, node->left);
        else                      insert(key, node->right);
    }

    void insert(int key) { insert(key, root); }

    void inverse(TreeNode *&node) {
        if (node == nullptr) return;
        inverse(node->left);
        inverse(node->right);
        swap(node->left, node->right);
    }

    void inverse() { inverse(root); }

    void preorder(TreeNode *node, vector<int> &result) {
        if (node == nullptr) return;
        result.push_back(node->key);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    vector<int> preorder() {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void postorder(TreeNode *node, vector<int> &result) {
        if (node == nullptr) return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->key);
    }

    vector<int> postorder() {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++) cin >> order[i];
    Tree origin(order);
    Tree mirror(order); mirror.inverse();

    vector<int> ans;
    if (order == origin.preorder()) ans = origin.postorder();
    if (order == mirror.preorder()) ans = mirror.postorder();

    cout << (!ans.empty() ? "YES" : "NO") << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    return 0;
}