#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *lchild = nullptr;
    TreeNode *rchild = nullptr;

    TreeNode(int key) : key(key) {}
};

void insert(TreeNode *&node, int key) {
    if (node == nullptr)       node = new TreeNode(key);
    else if (key <= node->key) insert(node->lchild, key);
    else                       insert(node->rchild, key);
}

const int N = 1005;
int max_level, cnt[N];
void dfs(TreeNode *node, int level) {
    if (node == nullptr) return;
    max_level = max(level, max_level);
    cnt[level]++;
    dfs(node->lchild, level + 1);
    dfs(node->rchild, level + 1);
}

int main() {
    int n, key;
    TreeNode *root = nullptr;
    cin >> n;
    while (n--) {
        cin >> key;
        insert(root, key);
    }
    dfs(root, 0);
    int n1 = cnt[max_level], n2 = cnt[max_level - 1];
    printf("%d + %d = %d\n", n1, n2, n1 + n2);
    return 0;
}