#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int key) : key(key), left(nullptr), right(nullptr) {}
};

using Iterator = vector<int>::iterator;

TreeNode* create_tree(Iterator pre, Iterator in, int len) {
    if (len <= 0) return nullptr;

    int i = 0;
    TreeNode *root = new TreeNode(*pre);
    while (i < len && in[i] != root->key) i++;
    root->left  = create_tree(pre + 1, in, i);
    root->right = create_tree(pre + i + 1, in + i + 1, len - i - 1);
    return root;
}

void post_order(TreeNode *root) {
    if (root == nullptr) return;

    post_order(root->left);
    post_order(root->right);
    cout << root->key << ' ';
}

int main() {
    int n;
    cin >> n;
    vector<int> s, pre, in;
    for (int i = 0; i < 2 * n; i++) {
        string op;
        cin >> op;
        if (op == "Push") {
            int key;
            cin >> key;
            s.push_back(key);
            pre.push_back(key);
        } else {
            in.push_back(s.back());
            s.pop_back();
        }
    }
    TreeNode *root = create_tree(pre.begin(), in.begin(), n);
    post_order(root->left);
    post_order(root->right);
    cout << root->key << endl;
    return 0;
}