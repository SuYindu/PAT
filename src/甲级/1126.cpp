// 注意判别图是否联通

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 505;
vector<int> graph[MAXN];

void DFS(int index, vector<bool> &visited) {
    visited[index] = true;
    for (auto v : graph[index])
        if (!visited[v]) DFS(v, visited);
}

bool IsConnected(int n) {
    vector<bool> visited(n + 1, false);
    DFS(1, visited);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int odd_count = 0;
    for (int i = 1; i <= n; i++) {
        cout << graph[i].size() << (i < n ? ' ' : '\n');
        if (graph[i].size() % 2 == 1) odd_count++;
    }
    bool is_connected = IsConnected(n);
    if (is_connected && odd_count == 0)
        cout << "Eulerian" << endl;
    else if (is_connected && odd_count == 2)
        cout << "Semi-Eulerian" << endl;
    else 
        cout << "Non-Eulerian" << endl;
    return 0;
}