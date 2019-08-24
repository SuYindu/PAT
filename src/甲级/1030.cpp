#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

const int N = 505;
int dist_graph[N][N], cost_graph[N][N];

int main() {
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    while (m--) {
        int v, w;
        cin >> v >> w >> dist_graph[v][w] >> cost_graph[v][w];
        dist_graph[w][v] = dist_graph[v][w];
        cost_graph[w][v] = cost_graph[v][w];
    }

    vector<bool> marked(N);
    vector<int> dist(N, INF), cost(N, INF), from(N, -1);
    dist[src] = cost[src] = 0;
    while (true) {
        int v = n;
        for (int w = 0; w < n; w++)
            if (!marked[w] && dist[w] < dist[v])
                v = w;
        if (v == dest) break;

        marked[v] = true;
        for (int w = 0; w < n; w++) {
            if (!dist_graph[v][w] || marked[w]) continue;
            if (dist[v] + dist_graph[v][w] < dist[w] || 
                    (dist[v] + dist_graph[v][w] == dist[w] && 
                     cost[v] + cost_graph[v][w] <  cost[w])) {
                dist[w] = dist[v] + dist_graph[v][w];
                cost[w] = cost[v] + cost_graph[v][w];
                from[w] = v;
            }
        }
    }

    vector<int> path;
    int temp = dest;
    while (temp != -1) {
        path.push_back(temp);
        temp = from[temp];
    }
    
    for (auto it = path.rbegin(); it != path.rend(); it++)
        printf("%d ", *it);
    printf("%d %d\n", dist[dest], cost[dest]);
    return 0;
}