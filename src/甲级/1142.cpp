#include <iostream>
#include <vector>
#include <set>
using namespace std;

void Output(bool is_clique, bool is_max) {
    if (!is_clique)
        cout << "Not a Clique" << endl;
    else if (!is_max)
        cout << "Not Maximal" << endl;
    else
        cout << "Yes" << endl;
}

void IsMaxClique(vector<int> vertices, vector<vector<int>> graph) {
    set<int> s;
    bool is_clique = true;
    bool is_max = true;
    for (auto u : vertices) s.insert(u);
    for (auto u : vertices) {
        int count = 0;
        for (auto v : graph[u])
            count += s.count(v);
        if (count < vertices.size() - 1) { is_clique = false; break; }
    }
    for (int u = 1; u < graph.size() && is_max; u++) {
        if (s.count(u)) continue;
        int count = 0;
        for (auto v : graph[u]) count += s.count(v);
        if (count >= vertices.size()) is_max = false;
    }
    Output(is_clique, is_max);
}

int main() {
    int nv, ne, m, k;
    cin >> nv >> ne;
    vector<vector<int>> graph(nv + 1);
    while (ne--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> m;
    while (m--) {
        cin >> k;
        vector<int> vertices(k);
        for (int i = 0; i < k; i++)
            cin >> vertices[i];
        IsMaxClique(vertices, graph);
    }
    return 0;
}