#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left  = NULL;
    TreeNode *right = NULL;
};

int Size(TreeNode *node) {
    if (node == NULL) return 0;
    return 1 + Size(node->left) + Size(node->right);
}

typedef vector<int>::iterator Iterator;

void FillKeys(TreeNode *node, Iterator begin, Iterator end) {
    if (node == NULL) return;
    int n = Size(node->left);
    node->key = *(begin + n);
    FillKeys(node->left, begin, begin + n - 1);
    FillKeys(node->right, begin + n + 1, end);
}

void BuildBinarySearchTree(vector<TreeNode> &nodes, vector<int> &keys) {
    sort(keys.begin(), keys.end());
    FillKeys(&nodes[0], keys.begin(), keys.end());
}

void LevelOrder(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *temp = q.front(); q.pop();
        if (temp != root) cout << ' ';
        cout << temp->key;
        if (temp->left  != NULL) q.push(temp->left );
        if (temp->right != NULL) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> nodes(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l != -1) nodes[i].left  = &nodes[l];
        if (r != -1) nodes[i].right = &nodes[r];
    }
    vector<int> keys(n);
    for (int i = 0; i < n; i++) cin >> keys[i];
    BuildBinarySearchTree(nodes, keys);
    LevelOrder(&nodes[0]);
    return 0;
}