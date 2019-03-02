// 使用 void reverse( BidirIt first, BidirIt last ) 来翻转字符串
// 注意操作符重载的语法

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct BigDecimal {
    static const int DECIMAL = 10;
    vector<int> digits;

    BigDecimal() {}
    BigDecimal(vector<int> digits) : digits(digits) {}

    friend istream& operator>>(istream& in, BigDecimal& x) {
        char c;
        while (in >> c) x.digits.push_back(c - '0');
        reverse(x.digits.begin(), x.digits.end());
        return in;
    }

    friend ostream& operator<<(ostream& out, const BigDecimal& x) {
        for (int i = x.digits.size() - 1; i >= 0; i--)
            out << x.digits[i];
        return out;
    }

    BigDecimal& operator+=(const BigDecimal& y) {
        const int n = max(digits.size(), y.digits.size());
        digits.resize(n);
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int a = i < digits.size() ? digits[i] : 0;
            int b = i < y.digits.size() ? y.digits[i] : 0;
            int sum = a + b + carry;
            digits[i] = sum % DECIMAL;
            carry = sum / DECIMAL;
        }
        if (carry > 0) digits.push_back(carry);
        return *this;
    }

    BigDecimal Reverse() {
        BigDecimal reversed(digits);
        reverse(reversed.digits.begin(), reversed.digits.end());
        return reversed;
    }
};

bool IsPalindromic(BigDecimal x) {
    for (int i = 0, j = x.digits.size() - 1; i < j; i++, j--)
        if (x.digits[i] != x.digits[j]) return false;
    return true;
}

int main() {
    const int MAX_ITER = 10;
    int count = 0;
    BigDecimal x;
    cin >> x;
    while (!IsPalindromic(x) && count < MAX_ITER) {
        count++;
        BigDecimal y = x.Reverse();
        cout << x << " + " << y << " = ";
        x += y;
        cout << x << endl;
    }
    if (count < MAX_ITER)
        cout << x << " is a palindromic number." << endl;
    else
        cout << "Not found in " << MAX_ITER << " iterations." << endl;
    return 0;
}