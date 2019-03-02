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

    TreeNode(int key) : key(key), left(NULL), right(NULL) {}
};

struct AVLTree {
    TreeNode *root = NULL;

    TreeNode* LeftRotate(TreeNode *node) {
        TreeNode *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        return temp;
    }

    TreeNode* RightRotate(TreeNode *node) {
        TreeNode *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        return temp;
    }

    TreeNode* LeftRightRotate(TreeNode *node) {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    TreeNode* RightLeftRotate(TreeNode *node) {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    int GetHeight(TreeNode *node) {
        if (node == NULL) return 0;
        int l = GetHeight(node->left);
        int r = GetHeight(node->right);
        return max(l, r) + 1;
    }

    TreeNode* Insert(int key, TreeNode *node) {
        if (node == NULL) node = new TreeNode(key);
        if (key < node->key) {
            node->left = Insert(key, node->left);
            if (GetHeight(node->left) - GetHeight(node->right) >= 2)
                node = key < node->left->key ? RightRotate(node) : LeftRightRotate(node);
        } else if (key > node->key) {
            node->right = Insert(key, node->right);
            if (GetHeight(node->right) - GetHeight(node->left) >= 2)
                node = key > node->right->key ? LeftRotate(node) : RightLeftRotate(node);
        }
        return node;
    }

    void Insert(int key) {
        root = Insert(key, root);
    }

    void LevelOrder() {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *temp = q.front(); q.pop();
            if (temp != root) cout << ' ';
            cout << temp->key;
            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }

    bool IsComplete() {
        queue<TreeNode*> q;
        q.push(root);
        while (true) {
            TreeNode *temp = q.front(); q.pop();
            if (temp == NULL) break;
            q.push(temp->left);
            q.push(temp->right);
        }
        while (!q.empty()) {
            if (q.front() != NULL) return false;
            q.pop();
        }
        return true;
    }
};

int main() {
    AVLTree tree;
    int n;
    cin >> n;
    while (n--) {
        int key;
        cin >> key;
        tree.Insert(key);
    }
    tree.LevelOrder();
    cout << (tree.IsComplete() ? "YES" : "NO") << endl;
    return 0;
}