#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m, k, num;
    cin >> n;
    vector<set<int>> sets(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> num;
            sets[i].insert(num);
        }
    }
    cin >> k;
    while (k--) {
        int i, j, count = 0;
        cin >> i >> j;
        for (auto num : sets[i])
            count += sets[j].count(num);
        printf("%.1f%%\n", 100.0 * count / (sets[i].size() + sets[j].size() - count));
    }
    return 0;
}