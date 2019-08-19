// 无需维护树节点的 height 属性，可简化代码

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
};

struct AVLTree {
    TreeNode *root = nullptr;

    TreeNode* left_rotate(TreeNode *node) {
        TreeNode *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }

    TreeNode* right_rotate(TreeNode *node) {
        TreeNode *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    TreeNode* left_right_rotate(TreeNode *node) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    TreeNode* right_left_rotate(TreeNode *node) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    int get_height(TreeNode *node) {
        if (node == nullptr) return 0;
        int l = get_height(node->left);
        int r = get_height(node->right);
        return max(l, r) + 1;
    }

    TreeNode* insert(int key, TreeNode *node) {
        if (node == nullptr) node = new TreeNode(key);
        if (key < node->key) {
            node->left = insert(key, node->left);
            if (get_height(node->left) - get_height(node->right) >= 2)
                node = key < node->left->key ? right_rotate(node) : left_right_rotate(node);
        } else if (key > node->key) {
            node->right = insert(key, node->right);
            if (get_height(node->right) - get_height(node->left) >= 2)
                node = key > node->right->key ? left_rotate(node) : right_left_rotate(node);
        }
        return node;
    }

    void insert(int key) {
        root = insert(key, root);
    }

    void bfs() {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front(); q.pop();
            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
            cout << temp->key << (!q.empty() ? ' ' : '\n');
        }
    }

    bool is_complete() {
        queue<TreeNode*> q;
        q.push(root);
        while (true) {
            TreeNode *temp = q.front(); q.pop();
            if (temp == nullptr) break;
            q.push(temp->left);
            q.push(temp->right);
        }
        while (!q.empty()) {
            if (q.front()) return false;
            q.pop();
        }
        return true;
    }
};

int main() {
    AVLTree tree;
    int n, key;
    cin >> n;
    while (n--) {
        cin >> key;
        tree.insert(key);
    }
    tree.bfs();
    cout << (tree.is_complete() ? "YES" : "NO") << endl;
    return 0;
}