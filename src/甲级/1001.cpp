#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    if (sum < 0) {
        cout << '-';
        sum *= -1;
    }
    string str = to_string(sum);
    int n = str.length();
    for (int i = 0; i < n; i++) {
        cout << str[i];
        if (i != n - 1 && (n - 1 - i) % 3 == 0) cout << ',';
    }
    return 0;
}