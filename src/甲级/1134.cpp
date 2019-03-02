#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

typedef pair<int, int> Edge;
set<Edge> edges;

bool IsVertexCover(unordered_set<int> vertices) {
    for (Edge edge : edges)
        if (!vertices.count(edge.first) && !vertices.count(edge.second))
            return false;
    return true;
}

int main() {
    int m, n, k;
    cin >> n >> m;
    while (m--) { int u, v; cin >> u >> v; edges.insert({u, v}); }
    cin >> k;
    while (k--) {
        int n, u;
        cin >> n;
        unordered_set<int> vertices;
        while (n--) { cin >> u; vertices.insert(u); }
        cout << (IsVertexCover(vertices) ? "Yes" : "No") << endl;
    }
    return 0;
}