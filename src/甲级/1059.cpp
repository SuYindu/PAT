#include <iostream>
#include <vector>
using namespace std;

struct Factor {
    int factor;
    int count;
};

const int MAXF = 10005;

int main() {
    int n;
    cin >> n;
    if (n == 1) { cout << "1=1" << endl; return 0; }
    
    vector<int> primes;
    vector<bool> is_prime(MAXF, true);
    for (int i = 2; i < MAXF; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < MAXF; j += i)
            is_prime[j] = false;
    }
    
    int tmp = n;
    vector<Factor> ans;
    for (int i = 0; i < MAXF; i++) {
        if (primes[i] > tmp / primes[i]) break;
        if (tmp % primes[i]) continue;

        int count = 0;
        while (tmp % primes[i] == 0) {
            count++;
            tmp /= primes[i];
        }
        ans.push_back(Factor{primes[i], count});
    }
    if (tmp != 1) ans.push_back(Factor{tmp, 1});
    
    cout << n << "=";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].factor;
        if (ans[i].count > 1) cout << "^" << ans[i].count;
        cout << (i < ans.size() - 1 ? '*' : '\n');
    }
    return 0;
}