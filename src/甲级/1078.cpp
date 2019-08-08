#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n) {
    if (n < 3) return n == 2;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= n / i; i++)
        if (n % i == 0) return false;
    return true;
}

int next_prime(int n) {
    if (n < 2) return 2;
    int res = n & 1 ? n : n + 1;
    while (!is_prime(res)) res += 2;
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;
    int capacity = next_prime(m);
    vector<int> ans(n, -1), hash_table(capacity);
    
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int hash_value = key % capacity;
        for (int j = 0; j < capacity; j++) {
            int pos = (hash_value + j * j) % capacity;
            if (hash_table[pos] == 0) {
                hash_table[pos] = key;
                ans[i] = pos;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) cout << "-";
        else              cout << ans[i];
        cout << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}