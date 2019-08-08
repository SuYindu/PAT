#include <iostream>
#include <string>
using namespace std;

bool is_prime(int n) {
    if (n < 3) return n == 2;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= n / i; i += 2)
        if (n % i == 0) return false;
    return true;
}

int inverse(int n, int d) {
    int res = 0;
    while (n) {
        res = res * d + n % d;
        n /= d;
    }
    return res;
}

int main() {
    int n, d;
    while (cin >> n >> d && n > 0)
        cout << (is_prime(n) && is_prime(inverse(n, d)) ? "Yes" : "No") << endl;
    return 0;
}