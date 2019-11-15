#include <iostream>
#include <vector>
using namespace std;

const int N = 505, INF = 0x3f3f3f3f;
int n, m, cnt[N], num[N], weight[N], graph[N][N];

void shortest_path(int src, int dest) {
    vector<bool> marked(n);
    vector<int> dist(n + 1, INF);

    dist[src] = 0;
    cnt[src] = 1;
    num[src] = weight[src];
    
    while (true) {
        int v = n;
        for (int w = 0; w < n; w++)
            if (!marked[w] && dist[w] < dist[v])
                v = w;
        if (v == dest) break;

        marked[v] = true;
        for (int w = 0; w < n; w++) {
            if (!graph[v][w] || marked[w]) continue;
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
                cnt[w] = cnt[v];
                num[w] = num[v] + weight[w];
            } else if (dist[v] + graph[v][w] == dist[w]) {
                cnt[w] += cnt[v];
                num[w] = max(num[v] + weight[w], num[w]);
            }
        }
    }
}

int main() {
    int src, dest;
    cin >> n >> m >> src >> dest;
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    while (m--) {
        int v, w;
        cin >> v >> w >> graph[v][w];
        graph[w][v] = graph[v][w];
    }
    shortest_path(src, dest);
    cout << cnt[dest] << " " << num[dest] << endl;
    return 0;
}