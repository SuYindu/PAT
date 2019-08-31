#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    int lchild, rchild;
};

int n;
const int N = 25;
Node nodes[N];

void dfs(int id) {
    if (id == -1) return;
    if (nodes[id].lchild == -1 && nodes[id].rchild == -1) {
        cout << nodes[id].data;
        return;
    }
    cout << "(";
    dfs(nodes[id].lchild);
    cout << nodes[id].data;
    dfs(nodes[id].rchild);
    cout << ")";
}

void dfs() {
    vector<bool> is_root(n + 1, true);
    for (int i = 1; i <= n; i++) {
        if (nodes[i].lchild != -1) is_root[nodes[i].lchild] = false;
        if (nodes[i].rchild != -1) is_root[nodes[i].rchild] = false;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (is_root[i]) root = i;
    dfs(nodes[root].lchild);
    cout << nodes[root].data;
    dfs(nodes[root].rchild);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nodes[i].data >> nodes[i].lchild >> nodes[i].rchild;
    dfs();
    return 0;
}