#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool judge(set<pair<int, int>> &edges, vector<int> &path, int n) {
    if (path.size() != n + 1)        return false;
    if (path.front() != path.back()) return false;

    set<int> vertices;
    for (int i = 0; i < path.size() - 1; i++) {
        if (!edges.count({path[i], path[i+1]})) return false;
        vertices.insert(path[i]);
    }
    return vertices.size() == n;
}

int main() {
    int n, m, k;
    cin >> n >> m;
    set<pair<int, int>> edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
        edges.insert({v, u});
    }
    cin >> k;
    while (k--) {
        int len;
        cin >> len;
        vector<int> path(len);
        for (int i = 0; i < len; i++)
            cin >> path[i];
        cout << (judge(edges, path, n) ? "YES" : "NO") << endl;
    }
    return 0;
}