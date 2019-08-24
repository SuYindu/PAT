#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

int INF = 0x3f3f3f3f;

vector<int> bellman_ford(int src, Graph &graph1, Graph &graph2) {
    int n = graph1.size();
    vector<int> prev(n, -1);
    vector<int> dist1(n, INF);
    vector<int> dist2(n, INF);
    dist1[src] = dist2[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if ((dist1[u] + graph1[u][v] < dist1[v]) || 
            (dist1[u] + graph1[u][v] == dist1[v] && 
             dist2[u] + graph2[u][v] < dist2[v])) {
                dist1[v] = dist1[u] + graph1[u][v];
                dist2[v] = dist2[u] + graph2[u][v];
                prev[v] = u;
                q.push(v);
            }
        }
    }
    return prev;
}

int construct_path(int dest, Graph &graph, vector<int> &prev, vector<int> &path) {
    int result = 0;
    int cur = prev[dest], next = dest;
    while (cur != -1) {
        result += graph[cur][next];
        path.push_back(next);
        next = cur;
        cur = prev[cur];
    }
    path.push_back(next);
    return result;
}

int bellman_ford(int src, int dest, vector<int> &path, Graph &graph1, Graph &graph2) {
    vector<int> prev = bellman_ford(src, graph1, graph2);
    return construct_path(dest, graph1, prev, path);
}

void print(vector<int> &path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != path.size() - 1) printf(" -> ");
        printf("%d", path[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Graph temp_graph(n, vector<int>(n, 1));
    Graph dist_graph(n, vector<int>(n, INF));
    Graph time_graph(n, vector<int>(n, INF));
    while (m--) {
        int u, v, flag, dist, time;
        cin >> u >> v >> flag >> dist_graph[u][v] >> time_graph[u][v];
        if (flag != 1) {
            dist_graph[v][u] = dist_graph[u][v];
            time_graph[v][u] = time_graph[u][v];
        }
    }
    int src, dest;
    cin >> src >> dest;
    vector<int> shortest_path, quickest_path;
    int min_dist = bellman_ford(src, dest, shortest_path, dist_graph, time_graph);
    int min_time = bellman_ford(src, dest, quickest_path, time_graph, temp_graph);
    if (shortest_path != quickest_path) {
        printf("Distance = %d: ", min_dist); print(shortest_path);
        printf("Time = %d: "    , min_time); print(quickest_path);
    } else {
        printf("Distance = %d; Time = %d: ", min_dist, min_time);
        print(shortest_path);
    }
    return 0;
}