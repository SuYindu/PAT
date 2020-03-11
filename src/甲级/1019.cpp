#include <iostream>
#include <vector>
using namespace std;

bool is_palindromic(const vector<int> &digits) {
    int n = digits.size();
    for (int i = 0; i <= n / 2; i++)
        if (digits[i] != digits[n - i - 1])
            return false;
    return true;
}

int main() {
    int num, base;
    cin >> num >> base;
    vector<int> digits;
    do {
        digits.push_back(num % base);
        num /= base;
    } while (num);
    cout << (is_palindromic(digits) ? "Yes" : "No") << endl;
    for (int i = digits.size() - 1; i >= 0; i--)
        cout << digits[i] << (i > 0 ? ' ' : '\n');
    return 0;
}