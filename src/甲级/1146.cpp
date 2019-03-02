#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> Edge;
set<Edge> edges;

bool IsTopologicalOrder(vector<int> perm) {
    for (int i = 0; i < perm.size() - 1; i++)
        if (edges.count({perm[i + 1], perm[i]}))
            return false;
    return true;
}

int main() {
    vector<int> result;
    int n, m, k, index = 0;
    cin >> n >> m;
    while (m--) { int u, v; cin >> u >> v; edges.insert({u, v}); }
    cin >> k;
    while (k--) {
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            cin >> perm[i];
        if (!IsTopologicalOrder(perm))
            result.push_back(index);
        index++;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << (i < result.size() - 1 ? ' ' : '\n');
    return 0;
}