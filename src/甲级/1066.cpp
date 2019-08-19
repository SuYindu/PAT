#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct AVLTree {
    TreeNode *root = nullptr;

    int height(TreeNode *node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    void left_rotate(TreeNode *&node) {
        TreeNode *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void right_rotate(TreeNode *&node) {
        TreeNode *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }

    void insert(int key, TreeNode *&node) {
        if (node == nullptr) {
            node = new TreeNode(key);
        } else if (key < node->key) {
            insert(key, node->left);
            if (height(node->left) - height(node->right) == 2) {
                if (key < node->left->key) {
                    right_rotate(node);
                } else {
                    left_rotate(node->left);
                    right_rotate(node);
                }
            }
        } else {
            insert(key, node->right);
            if (height(node->right) - height(node->left) == 2) {
                if (key > node->right->key) {
                    left_rotate(node);
                } else {
                    right_rotate(node->right);
                    left_rotate(node);
                }
            }
        }
    }

    void insert(int key) { insert(key, root); }
};

int main() {
    int n, key;
    AVLTree tree;
    cin >> n;
    while (n--) {
        cin >> key;
        tree.insert(key);
    }
    cout << tree.root->key << endl;
    return 0;
}