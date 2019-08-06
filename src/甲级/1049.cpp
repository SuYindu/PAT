#include <iostream>
using namespace std;

int main() {
    int n, m = 1, ans = 0;
    cin >> n;
    while (n / m) {
        int left  = n / m / 10;
        int digit = n / m % 10;
        int right = n % m;
        if (digit == 0)      ans += left * m;
        else if (digit == 1) ans += left * m + right + 1;
        else                 ans += left * m + m;
        m *= 10;
    }
    cout << ans << endl;
    return 0;
}