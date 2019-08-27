#include <iostream>
using namespace std;

string describe(const string &num) {
    string res;
    for (int i = 0; i < num.size();) {
        char c = num[i];
        int count = 0;
        while (i < num.size() && num[i] == c) {
            i++;
            count++;
        }
        res += c + to_string(count);
    }
    return res;
}

int main() {
    int n;
    string ans;
    cin >> ans >> n;
    while (--n) ans = describe(ans);
    cout << ans << endl;
    return 0;
}