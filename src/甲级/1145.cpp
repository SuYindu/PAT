// 注意哈希表查找不存在元素时的判定，例如本题中的
// while (keys[index] != num && keys[index] != 0)

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i++)
        if (num % i == 0) return false;
    return true;
}

int NextPrime(int num) {
    if (num < 3) return 2;
    int res = num % 2 == 1 ? num : num + 1;
    while (!IsPrime(res)) res += 2;
    return res;
}

struct HashTable {
    vector<int> keys;
    
    HashTable(int size) : keys(NextPrime(size), 0) {}

    int Hash(int num) { return num % keys.size(); }

    bool Insert(int num) {
        int hash_val = Hash(num); 
        int index = hash_val, i = 0;
        while (keys[index] != 0) {
            if ((++i) >= keys.size()) return false;
            index = (hash_val + i * i) % keys.size();
        }
        keys[index] = num;
        return true;
    }

    int Find(int num) {
        int count = 1, i = 0;
        int hash_val = Hash(num);
        int index = hash_val;
        while (keys[index] != num && keys[index] != 0) {
            if ((++i) > keys.size()) break;
            count++;
            index = (hash_val + i * i) % keys.size();
        }
        return count;
    }
};

int main() {
    int num, size, n, m;
    cin >> size >> n >> m;
    HashTable hash_table(size);
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (!hash_table.Insert(num))
            printf("%d cannot be inserted.\n", num);
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        cin >> num;
        count += hash_table.Find(num);
    }
    printf("%.1f\n", (double)count / m);
    return 0;
}