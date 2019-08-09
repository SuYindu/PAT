// 注意乘积会超出 int 的表示范围
// 注意 n 是质数的特殊情况

#include <iostream>
using namespace std;

int main() {
    int n, max_len = 0;
    long long product = 1;
    cin >> n;
    for (int i = 2; product <= n; product *= i, i++) max_len++;
    for (int len = max_len - 1; len >= 1; len--) {
        for (int begin = 2; begin <= n / begin; begin++) {
            product = 1;
            for (int i = begin; i < begin + len; i++) product *= i;
            if (n % product) continue;
            
            cout << len << endl;
            for (int i = begin; i < begin + len; i++)
                cout << i << (i < begin + len - 1 ? '*' : '\n');
            return 0;
        }
    }
    cout << 1 << endl << n << endl;
    return 0;
}