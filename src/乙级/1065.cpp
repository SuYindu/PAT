#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, x, y;
    set<int> guests;
    set<pair<int, int>> couple;
    cin >> n;
    while (n--) { cin >> x >> y; couple.insert({x, y}); }
    cin >> m;
    while (m--) { cin >> x; guests.insert(x); }

    for (auto pair : couple) {
        x = pair.first; y = pair.second;
        if (guests.count(x) && guests.count(y)) {
            guests.erase(x);
            guests.erase(y);
        }
    }

    if (guests.empty()) { printf("0\n"); return 0; }
    printf("%lu\n", guests.size());
    for (auto it = guests.begin(); it != guests.end(); it++) {
        if (it != guests.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}