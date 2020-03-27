#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int n1 = (n + 2) / 3, n2 = n + 2 - 2 * n1;
    for (int i = 0; i < n1 - 1; i++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j++)
            cout << ' ';
        cout << s[n - i - 1] << endl;
    }
    for (int i = 0; i < n2; i++)
        cout << s[i + n1 - 1];
    return 0;
}