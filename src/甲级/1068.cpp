#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10005, M = 105;
bool mark[N][M];
int w[N], dp[M];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        for (int v = m; v >= w[i]; v--) {
            if (dp[v] <= dp[v - w[i]] + w[i]) {
                dp[v] = dp[v - w[i]] + w[i];
                mark[i][v] = true;
            }
        }
    }
    if (dp[m] != m) { cout << "No Solution"; return 0; }
    vector<int> ans;
    for (int i = n, v = m; i >= 0; i--) {
        if (mark[i][v]) {
            v -= w[i];
            ans.push_back(w[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    return 0;
}