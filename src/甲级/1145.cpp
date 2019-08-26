#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int next_prime(int num) {
    num = num % 2 ? num : num + 1;
    while (!is_prime(num)) num += 2;
    return num;
}

struct HashTable {
    vector<int> table;

    HashTable(int size) : table(next_prime(size)) {}

    int hash(int key) { return key % table.size(); }

    bool insert(int key) {
        int hash_val = hash(key);
        for (int i = 0; i < table.size(); i++) {
            int pos = (hash_val + i * i) % table.size();
            if (table[pos] == 0) {
                table[pos] = key;
                return true;
            }
        }
        return false;
    }

    int search(int key) {
        int hash_val = hash(key), count = 0;
        for (int i = 0; i <= table.size(); i++) {
            count++;
            int val = table[(hash_val + i * i) % table.size()];
            if (val == 0 || val == key) break;
        }
        return count;
    }
};

int main() {
    int size, n, m, key, count = 0;
    cin >> size >> n >> m;
    HashTable hash_table(size);
    while (n--) {
        cin >> key;
        if (!hash_table.insert(key))
            printf("%d cannot be inserted.\n", key);
    }
    for (int i = 0; i < m; i++) {
        cin >> key;
        count += hash_table.search(key);
    }
    printf("%.1f\n", (double)count / m);
    return 0;
}