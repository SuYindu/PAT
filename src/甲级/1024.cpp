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

    bool is_palindromic() {
        int i = 0, j = digits.size() - 1;
        while (i < j)
            if (digits[i++] != digits[j--]) return false;
        return true;
    }

    BigInt reversed() {
        BigInt res;
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
            res.digits.push_back(*it);
        return res;
    }

    friend BigInt operator+(BigInt a, BigInt b) {
        BigInt c;
        int carry = 0, m = a.digits.size(), n = b.digits.size();
        for (int i = 0; i < m || i < n; i++) {
            int temp = carry;
            temp += i < m ? a.digits[i] : 0;
            temp += i < n ? b.digits[i] : 0;
            c.digits.push_back(temp % 10);
            carry = temp / 10;
        }
        if (carry) c.digits.push_back(carry);
        return c;
    }
};

int main() {
    BigInt num;
    int k, count = 0;
    cin >> num >> k;
    while (!num.is_palindromic() && count < k) {
        num = num + num.reversed();
        count++;
    }
    cout << num << endl << count << endl;
    return 0;
}