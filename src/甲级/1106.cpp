#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MY_INFINITY = 0x3f3f3f3f;

vector<int> ShortestPath(int src, const vector<vector<int>> &graph) {
    vector<int> dist(graph.size(), MY_INFINITY);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int n;
    double price, rate;
    cin >> n >> price >> rate;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        graph[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> graph[i][j];
    }
    vector<int> dist = ShortestPath(0, graph);
    int min = MY_INFINITY, count;
    for (int i = 0; i < n; i++) {
        // 跳过供应商和经销商
        if (graph[i].size() != 0) continue;
        if (dist[i] < min) {
            min = dist[i];
            count = 1;
        } else if (dist[i] == min) {
            count++;
        }
    }
    printf("%.4f %d\n", price * pow(1 + rate / 100, min), count);
    return 0;
}