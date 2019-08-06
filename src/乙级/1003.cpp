#include <iostream>
using namespace std;

bool accept(string s) {
    int n = s.length(), p = -1, t = -1;
    for (int i = 0; i < n; i++) {
        switch(s[i]) {
        case 'P':
            if (p == -1) p = i;
            else return false;
            break;
        case 'T':
            if (t == -1) t = i;
            else return false;
            break;
        case 'A':
            break;
        default:
            return false;
        }
    }
    if (p + 2 == t && 2 * p + 3 == n && s[p + 1] == 'A') return true;
    string a = s.substr(0, p);
    string b = s.substr(p + 1, t - p - 2);
    string c = s.substr(t + 1, n - 1 - p - t);
    return accept(a + "P" + b + "T" + c);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << (accept(s) ? "YES" : "NO") << endl;
    }
    return 0;
}  