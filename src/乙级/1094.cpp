#include <iostream>
#include <string>
using namespace std;

bool is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int main() {
    bool found = false;
    int l, k;
    string num, ans;
    cin >> l >> k >> num;
    for (int i = 0; i <= l - k && !found; i++) {
        ans = num.substr(i, k);
        if (is_prime(stoi(ans))) found = true;
    }
    cout << (found ? ans : "404") << endl;
    return 0;
}