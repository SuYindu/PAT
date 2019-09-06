#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *lchild = nullptr;
    TreeNode *rchild = nullptr;

    TreeNode(int key) : key(key) {}
};

int height(TreeNode *node) {
    if (node == nullptr) return 0;
    return max(height(node->lchild), height(node->rchild)) + 1;
}

void left_rotate(TreeNode *&node) {
    TreeNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node = temp;
}

void right_rotate(TreeNode *&node) {
    TreeNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node = temp;
}

void insert(TreeNode *&node, int key) {
    if (node == nullptr) { node = new TreeNode(key); return; }
    if (key < node->key) {
        insert(node->lchild, key);
        if (height(node->lchild) - height(node->rchild) == 2) {
            if (key > node->lchild->key)
                left_rotate(node->lchild);
            right_rotate(node);
        }
    } else if (key > node->key) {
        insert(node->rchild, key);
        if (height(node->rchild) - height(node->lchild) == 2) {
            if (key < node->rchild->key)
                right_rotate(node->rchild);
            left_rotate(node);
        }
    }
}

void bfs(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        if (temp->lchild) q.push(temp->lchild);
        if (temp->rchild) q.push(temp->rchild);
        cout << temp->key << (!q.empty() ? ' ' : '\n');
    }
}

bool judge(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (q.front()) {
        TreeNode *temp = q.front(); q.pop();
        q.push(temp->lchild);
        q.push(temp->rchild);
    }
    while (!q.empty()) {
        if (q.front()) return false;
        q.pop();
    }
    return true;
}

int main() {
    int n, key;
    cin >> n;
    TreeNode *root = nullptr;
    while (n--) {
        cin >> key;
        insert(root, key);
    }
    bfs(root);
    cout << (judge(root) ? "YES" : "NO") << endl;
    return 0;
}