#include <iostream>
using namespace std;

const int N = 205, L = 10005;
int s1[N], s2[L], dp[N][L];

int main() {
    int n, m, l;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> s1[i];
    cin >> l;
    for (int i = 1; i <= l; i++) cin >> s2[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= l; j++) {
            int tmp = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = s1[i] == s2[j] ? tmp + 1 : tmp;
        }
    }
    cout << dp[m][l] << endl;
    return 0;
}