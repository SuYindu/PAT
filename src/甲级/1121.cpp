#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, x, y;
    set<pair<int, int>> couple;
    set<int> single;
    cin >> n;
    while (n--) { cin >> x >> y; couple.insert({x, y}); }
    cin >> m;
    while (m--) { cin >> x; single.insert(x); }

    for (auto pair : couple) {
        x = pair.first;
        y = pair.second;
        if (single.count(x) && single.count(y)) {
            single.erase(x);
            single.erase(y);
        }
    }

    if (single.empty()) { printf("0\n"); return 0; }
    printf("%d\n", single.size());
    for (auto it = single.begin(); it != single.end(); it++) {
        if (it != single.begin()) printf(" ");
        printf("%05d", *it);
    }
    printf("\n");
    return 0;
}