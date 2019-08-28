#include <iostream>
using namespace std;

int flag, ans;

void dfs(int *pre, int *in, int n) {
    if (n <= 0) return;
    int i = 0;
    while (i < n && in[i] != *pre) i++;
    dfs(pre + 1, in, i);
    dfs(pre + i + 1, in + i + 1, n - i - 1);
    if (!flag) { flag = 1; ans = *pre; }
}

int main() {
    int n;
    cin >> n;
    int pre[n], in[n];
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> in[i];
    dfs(pre, in, n);
    cout << ans << endl;
    return 0;
}