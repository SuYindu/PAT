#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BigInt {
    vector<int> digits;

    friend istream& operator>>(istream &in, BigInt &num) {
        string str;
        cin >> str;
        for (auto it = str.rbegin(); it != str.rend(); it++)
            num.digits.push_back(*it - '0');
        return in;
    }

    friend ostream& operator<<(ostream &out, const BigInt &num) {
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); it++)
            cout << *it;
        return out;
    }

    friend BigInt multiply(const BigInt &a, int b) {
        BigInt c;
        int carry = 0;
        for (auto d : a.digits) {
            int temp = d * b + carry;
            c.digits.push_back(temp % 10);
            carry = temp / 10;
        }
        while (carry) {
            c.digits.push_back(carry % 10);
            carry /= 10;
        }
        return c;
    }
};

int main() {
    BigInt num;
    cin >> num;
    vector<int> count(10);
    for (auto d : num.digits) count[d]++;
    num = multiply(num, 2);
    for (auto d : num.digits) count[d]--;
    bool flag = true;
    for (auto num : count)
        if (num != 0) flag = false;
    cout << (flag ? "Yes" : "No") << endl << num << endl;
    return 0;
}