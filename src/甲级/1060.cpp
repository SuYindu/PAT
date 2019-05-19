#include <iostream>
using namespace std;

string transfer(string num, int n) {
    int i = 0, exp = 0, count = 0;
    string res = "0.";
    while (num[i] == '0') i++;
    if (num[i] == '.')
        while (num[++i] == '0') exp--;
    else
        exp = num.find('.') == string::npos ? num.size() - i : num.find('.') - i;
    for (; count < n; i++) {
        if (num[i] == '.') continue;
        res += i < num.size() ? num[i] : '0';
        count++;
    }
    if (stof(res) == 0.0) exp = 0;
    res += "*10^" + to_string(exp);
    return res;
}

int main() {
    int n;
    string num1, num2;
    cin >> n >> num1 >> num2;
    string s1 = transfer(num1, n), s2 = transfer(num2, n);
    if (s1 == s2) cout << "YES " << s1;
    else          cout << "NO "  << s1 << " " << s2;
    return 0;
}