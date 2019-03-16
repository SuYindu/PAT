#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
    int count = 0;
    for (int i = 3; i <= n - 2; i += 2)
        count += (is_prime[i] && is_prime[i + 2]);
    cout << count << endl;
    return 0;
}