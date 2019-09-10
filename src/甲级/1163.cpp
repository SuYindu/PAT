#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1005;
int graph[N][N];

bool judge(vector<int> order) {
    int n = order.size();
    vector<bool> mark(n + 1);
    vector<int> dist(n + 2, INF);
    dist[order.front()] = 0;
    for (auto v : order) {
        for (int w = 1; w <= n; w++)
            if (!mark[w] && dist[w] < dist[v])
                return false;
        mark[v] = true;
        for (int w = 1; w <= n; w++)
            if (graph[v][w] != 0)
                dist[w] = min(dist[v] + graph[v][w], dist[w]);
    }
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w >> graph[v][w];
        graph[w][v] = graph[v][w];
    }
    cin >> k;
    while (k--) {
        vector<int> order(n);
        for (int i = 0; i < n; i++)
            cin >> order[i];
        cout << (judge(order) ? "Yes" : "No") << endl;
    }
    return 0;
}