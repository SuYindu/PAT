#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<pair<int, int>> edges;

bool judge(set<int> &vertices) {
    for (auto edge : edges)
        if (!vertices.count(edge.first) && !vertices.count(edge.second))
            return false;
    return true;
}

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    while (m--) { int v, w; scanf("%d%d", &v, &w); edges.push_back({v, w}); }
    scanf("%d", &k);
    while (k--) {
        int l, v;
        set<int> vertices;
        scanf("%d", &l);
        while (l--) { scanf("%d", &v); vertices.insert(v); }
        cout << (judge(vertices) ? "Yes" : "No") << endl;
    }
    return 0;
}