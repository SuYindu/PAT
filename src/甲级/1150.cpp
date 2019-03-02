// 注意用邻接矩阵表示无向图时边的输入（两个方向）

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> Edge;
const int NOT_A_EDGE = -1;
const int NOT_A_PATH = -1;
const int MAXN = 205;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, NOT_A_EDGE));
vector<Edge> paths;

bool IsTSCycle(vector<int> path, int n) {
    for (int i = 0; i < path.size() - 1; i++)
        if (graph[path[i]][path[i + 1]] == NOT_A_EDGE)
            return false;
    set<int> visited;
    for (auto v : path)
        visited.insert(v);
    return visited.size() == n && path.front() == path.back();
}

bool IsSimple(vector<int> path) {
    set<Edge> visited;
    for (int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        if (visited.count({u, v})) return false;
        visited.insert({u, v});
        visited.insert({v, u});
    }
    return true;
}

int GetDistance(vector<int> path) {
    int dist = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int edge = graph[path[i]][path[i + 1]];
        if (edge == NOT_A_EDGE) return NOT_A_PATH;
        dist += edge;
    }
    return dist;
}

void PrintResult(bool is_tscycle, bool is_simple, int dist) {
    static int kase = 0;
    printf("Path %d: ", ++kase);
    if (is_tscycle && dist != NOT_A_PATH)
        paths.push_back({kase, dist});
    if (dist != NOT_A_PATH) cout << dist << " ";
    else                    cout << "NA" << " ";
    
    if (!is_tscycle)     cout << "(Not a TS cycle)" << endl;
    else if (!is_simple) cout << "(TS cycle)" << endl;
    else                 cout << "(TS simple cycle)" << endl;
}

int main() {
    int m, n, k, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        graph[u][v] = dist;
        graph[v][u] = dist;
    }
    cin >> k;
    while (k--) {
        cin >> l;
        vector<int> path(l);
        for (int i = 0; i < l; i++)
            cin >> path[i];
        PrintResult(IsTSCycle(path, n), IsSimple(path), GetDistance(path));
    }
    sort(paths.begin(), paths.end(), 
    [](Edge a, Edge b) {
        return a.second < b.second;
    });
    int best_index = (*paths.begin()).first;
    int min_dist = (*paths.begin()).second;
    printf("Shortest Dist(%d) = %d\n", best_index, min_dist);
    return 0;
}