#include <iostream>
#include <vector>
using namespace std;

bool flag = true;
vector<int> ans;

void build(int *pre, int *post, int n) {
    if (n <= 0) return;
    if (n == 1) { ans.push_back(pre[0]); return; }
    
    int i = 0;
    while (i < n && post[i] != pre[1]) i++;
    if (i == n - 2) flag = false;
    build(pre + 1, post, i + 1);
    ans.push_back(pre[0]);
    build(pre + i + 2, post + i + 1, n - i - 2);
}

int main() {
    int n;
    cin >> n;
    int pre[n], post[n];
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    build(pre, post, n);
    cout << (flag ? "Yes" : "No") << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}