#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int digit_sum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int k, m;
        cin >> k >> m;
        vector<pair<int, int>> ans;
        int begin = pow(10, k - 1), end = pow(10, k);
        for (int i = begin + 9; i < end; i += 10) {
            if (digit_sum(i) != m) continue;
            int n = digit_sum(i + 1), d = gcd(m, n);
            if (is_prime(d) && d > 2)
                ans.push_back({n, i});
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        });
        printf("Case %d\n", i);
        if (ans.empty()) printf("No Solution\n");
        for (auto entry : ans)
            printf("%d %d\n", entry.first, entry.second);
    }
    return 0;
}