// 对于稀疏图，注意防止内存超限（存储边）

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<pair<int, int>> edges;

bool IsProper(const vector<int> &colors) {
    for (int i = 0; i < edges.size(); i++)
        if (colors[edges[i].first] == colors[edges[i].second])
            return false;
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; edges[i] = {u, v}; }
    cin >> k;
    while (k--) {
        vector<int> colors(n);
        set<int> diff_color;
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
            diff_color.insert(colors[i]);
        }
        if (IsProper(colors)) printf("%d-coloring\n", diff_color.size());
        else                  printf("No\n");
    }
    return 0;
}