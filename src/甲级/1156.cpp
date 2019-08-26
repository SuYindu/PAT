#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int main() {
    int num;
    cin >> num;
    if (is_prime(num) && is_prime(num - 6)) {
        cout << "Yes" << endl << num - 6 << endl;
    } else if (is_prime(num) && is_prime(num + 6)) {
        cout << "Yes" << endl << num + 6 << endl;
    } else {
        int ans = num & 1 ? num + 2 : num + 1;
        while (!(is_prime(ans) && (is_prime(ans - 6) || is_prime(ans + 6))))
            ans += 2;
        cout << "No" << endl << ans << endl;
    }
    return 0;
}