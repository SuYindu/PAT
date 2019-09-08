#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct BigInt {
    vector<int> digits;

    BigInt(vector<int> digits) : digits(digits) {}

    BigInt reversed() {
        vector<int> tmp(digits.rbegin(), digits.rend());
        return BigInt(tmp);
    }

    bool is_palindromic() {
        for (int i = 0, j = digits.size() - 1; i < j; i++, j--)
            if (digits[i] != digits[j])
                return false;
        return true;
    }

    friend BigInt operator+(BigInt a, BigInt b) {
        const int n = a.digits.size(), m = b.digits.size();
        vector<int> tmp(max(n, m));
        int carry = 0;
        for (int i = 0; i < tmp.size(); i++) {
            int sum = carry;
            sum += i < n ? a.digits[i] : 0;
            sum += i < m ? b.digits[i] : 0;
            tmp[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) tmp.push_back(carry);
        return BigInt(tmp);
    }

    friend ostream& operator<<(ostream &out, const BigInt &x) {
        for (auto it = x.digits.rbegin(); it != x.digits.rend(); it++)
            out << *it;
        return out;
    }
};

int main() {
    char c;
    int count = 0;
    vector<int> tmp;
    while (cin >> c) tmp.push_back(c - '0');
    reverse(tmp.begin(), tmp.end());
    BigInt a(tmp);
    while (count < 10 && !a.is_palindromic()) {
        BigInt b = a.reversed();
        cout << a << " + " << b << " = " << (a = a + b) << endl;
        count++;
    }
    if (count < 10) cout << a << " is a palindromic number." << endl;
    else            cout << "Not found in 10 iterations." << endl;
    return 0;
}