#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    while (m--) {
        int v, w;
        cin >> v >> w;
        edges.push_back({v, w});
    }
    vector<int> ans, pos(n + 1);
    cin >> k;
    for (int i = 0; i < k; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;
            pos[v] = j;
        }
        for (auto edge : edges)
            if (pos[edge.first] > pos[edge.second])
                flag = false;
        if (!flag) ans.push_back(i);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    return 0;
}