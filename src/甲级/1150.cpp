#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
const int N = 205;
int graph[N][N];

vector<string> descriptions {
    "Not a TS cycle",
    "Not a TS cycle",
    "TS cycle",
    "TS simple cycle",
};

int get_dist(const vector<int> &path) {
    int res = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int len = graph[path[i]][path[i+1]];
        if (!len) return INF;
        res += len;
    }
    return res;
}

bool is_ts_cycle(const vector<int> &path) {
    for (int i = 0; i < path.size() - 1; i++)
        if (!graph[path[i]][path[i+1]])
            return false;
    set<int> visited(path.begin(), path.end());
    return visited.size() == n && path.front() == path.back();
}

bool is_simple(const vector<int> &path) {
    set<int> visited(path.begin(), path.end());
    return path.size() == visited.size() + 1 && path.front() == path.back();
}

int main() {
    cin >> n >> m;
    while (m--) {
        int v, w;
        cin >> v >> w >> graph[v][w];
        graph[w][v] = graph[v][w];
    }
    int min_dist = INF, min_idx, k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int l;
        cin >> l;
        vector<int> path(l);
        for (int j = 0; j < l; j++)
            cin >> path[j];
        int dist = get_dist(path);
        string dist_str = dist == INF ? "NA" : to_string(dist);
        int idx = is_ts_cycle(path) * 2 + is_simple(path);
        string description = descriptions[idx];
        printf("Path %d: %s (%s)\n", i, dist_str.c_str(), description.c_str());
        if (idx >= 2 && dist < min_dist) {
            min_dist = dist;
            min_idx = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", min_idx, min_dist);
    return 0;
}