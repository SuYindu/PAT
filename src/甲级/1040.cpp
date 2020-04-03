#include <iostream>
using namespace std;

int expand(int c1, int c2, const string &str) {
    int l = c1, r = c2;
    while (l >= 0 && r < str.size() && str[l] == str[r])
        l--, r++;
    return r - l - 1;
}

int main() {
    string str;
    getline(cin, str);
    int ans = 1;
    for (int i = 0; i < str.size() - 1; i++) {
        ans = max(expand(i, i, str), ans);
        ans = max(expand(i, i + 1, str), ans);
    }
    cout << ans << endl;
    return 0;
}