#include <iostream>
#include <vector>
using namespace std;

bool is_unique = true;

void InOrder(int *preorder, int *postorder, int n, vector<int> &inorder) {
    if (n <= 0) return;
    if (n == 1) { inorder.push_back(preorder[0]); return; }
    int i = 0;
    while (i < n && postorder[i] != preorder[1]) i++;
    if (i == n - 2) is_unique = false;
    InOrder(preorder + 1, postorder, i + 1, inorder);
    inorder.push_back(preorder[0]);
    InOrder(preorder + i + 2, postorder + i + 1, n - i - 2, inorder);
}

int main() {
    int n;
    cin >> n;
    int *preorder  = new int[n];
    int *postorder = new int[n];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    vector<int> inorder;
    InOrder(preorder, postorder, n, inorder);
    cout << (is_unique ? "Yes" : "No") << endl;
    for (int i = 0; i < n; i++)
        cout << inorder[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}