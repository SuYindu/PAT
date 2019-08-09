#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BigInt {
    vector<int> digits;

    friend istream& operator>>(istream &in, BigInt &num) {
        string str;
        in >> str;
        for (auto it = str.rbegin(); it != str.rend(); it++)
            num.digits.push_back(*it - '0');
        return in;
    }

    friend ostream& operator<<(ostream &out, const BigInt &num) {
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); it++)
            cout << *it;
        return out;
    }

    friend BigInt divide(BigInt a, int b, int &r) {
        r = 0;
        BigInt c;
        const int n = a.digits.size();
        c.digits.resize(n);
        for (int i = n - 1; i >= 0; i--) {
            r = r * 10 + a.digits[i];
            c.digits[i] = r / b;
            r %= b;
        }
        while (c.digits.size() > 1 && c.digits.back() == 0)
            c.digits.pop_back();
        return c;
    }
};

int main() {
    BigInt a;
    int b, r;
    cin >> a >> b;
    BigInt c = divide(a, b, r);
    cout << c << " " << r << endl;
}