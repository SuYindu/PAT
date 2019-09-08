#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> edges;
    while (m--) {
        int v, w;
        scanf("%d%d", &v, &w);
        edges.push_back({v, w});
    }
    scanf("%d", &k);
    while (k--) {
        bool flag = true;
        vector<int> colors(n);
        set<int> count;
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
            count.insert(colors[i]);
        }
        for (auto edge : edges)
            if (colors[edge.first] == colors[edge.second])
                flag = false;
        if (flag) printf("%lu-coloring\n", count.size());
        else      printf("No\n");
    }
    return 0;
}