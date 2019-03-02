// 注意掌握 Dijkstra 算法

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

typedef vector<vector<int>> Graph;

int INFINITY = 0x3f3f3f3f;

vector<int> Dijkstra(int src, Graph &graph1, Graph &graph2) {
    int n = graph1.size();
    vector<int> prev(n, -1);
    vector<int> dist1(n, INFINITY);
    vector<int> dist2(n, INFINITY);
    dist1[src] = dist2[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if ((dist1[u] + graph1[u][v] < dist1[v]) 
            || (dist1[u] + graph1[u][v] == dist1[v] && dist2[u] + graph2[u][v] < dist2[v])) {
                dist1[v] = dist1[u] + graph1[u][v];
                dist2[v] = dist2[u] + graph2[u][v];
                prev[v] = u;
                q.push(v);
            }
        }
    }
    return prev;
}

int ConstructPath(int dest, Graph &graph, vector<int> &prev, deque<int> &path) {
    int result = 0;
    int cur = prev[dest], next = dest;
    while (cur != -1) {
        result += graph[cur][next];
        path.push_front(next);
        next = cur;
        cur = prev[cur];
    }
    path.push_front(next);
    return result;
}

int ShortestPath(int src, int dest, deque<int> &path, Graph &graph1, Graph &graph2) {
    vector<int> prev = Dijkstra(src, graph1, graph2);
    return ConstructPath(dest, graph1, prev, path);
}

bool Equal(deque<int> &p1, deque<int> &p2) {
    return equal(p1.begin(), p1.end(), p2.begin(), p2.end());
}

void Print(deque<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) printf(" -> ");
        printf("%d", path[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Graph temp_graph(n, vector<int>(n, 1)); // 无权图
    Graph dist_graph(n, vector<int>(n, INFINITY));
    Graph time_graph(n, vector<int>(n, INFINITY));
    while (m--) {
        int u, v, flag, dist, time;
        scanf("%d%d%d%d%d", &u, &v, &flag, &dist, &time);
        dist_graph[u][v] = dist; time_graph[u][v] = time;
        if (flag != 1) { dist_graph[v][u] = dist; time_graph[v][u] = time; }
    }
    int src, dest;
    scanf("%d%d", &src, &dest);
    deque<int> shortest_path, quickest_path;
    int min_dist = ShortestPath(src, dest, shortest_path, dist_graph, time_graph);
    int min_time = ShortestPath(src, dest, quickest_path, time_graph, temp_graph);
    if (!Equal(shortest_path, quickest_path)) {
        printf("Distance = %d: ", min_dist); Print(shortest_path);
        printf("Time = %d: "    , min_time); Print(quickest_path);
    } else {
        printf("Distance = %d; Time = %d: ", min_dist, min_time);
        Print(shortest_path);
    }
    return 0;
}