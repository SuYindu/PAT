#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, v, w;
    set<int> ans;
    set<pair<int, int>> edges;
    cin >> n;
    while (n--) { cin >> v >> w; edges.insert({v, w}); }
    cin >> m;
    while (m--) { cin >> v; ans.insert(v); }
    for (auto edge : edges) {
        int v = edge.first, w = edge.second;
        if (ans.count(v) && ans.count(w)) {
            ans.erase(v);
            ans.erase(w);
        }
    }
    printf("%lu\n", ans.size());
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (it != ans.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}