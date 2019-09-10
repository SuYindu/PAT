#include <iostream>
using namespace std;

const int N = 25;
bool marked[N];
struct TreeNode {
    string data;
    int lchild, rchild;
} nodes[N];

void dfs(int id) {
    if (id == -1) return;
    int count = (nodes[id].lchild == -1) + (nodes[id].rchild == -1);
    cout << "(";
    if (count == 1) cout << nodes[id].data;
    dfs(nodes[id].lchild);
    dfs(nodes[id].rchild);
    if (count != 1) cout << nodes[id].data;
    cout << ")";
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].data >> nodes[i].lchild >> nodes[i].rchild;
        if (nodes[i].lchild != -1) marked[nodes[i].lchild] = true;
        if (nodes[i].rchild != -1) marked[nodes[i].rchild] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!marked[i]) dfs(i);
    return 0;
}