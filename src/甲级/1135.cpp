#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

bool flag;
int black_height;
int dfs(int *pre, int n, int count) {
    if (n <= 0) {
        if (black_height == 0) black_height = count;
        if (count != black_height) flag = false;
        return INF;
    }
    int root = pre[0], i = 1;
    while (i < n && abs(pre[i]) < abs(root)) i++;
    int lchild = dfs(pre + 1, i - 1, count + (root > 0));
    int rchild = dfs(pre + i, n - i, count + (root > 0));
    if (root < 0 && (lchild < 0 || rchild < 0)) flag = false;
    return root;
}

int main() {
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        int pre[n];
        for (int i = 0; i < n; i++) cin >> pre[i];
        flag = true;
        black_height = 0;
        dfs(pre, n, 0);
        cout << (flag && pre[0] > 0 ? "Yes" : "No") << endl;
    }
    return 0;
}