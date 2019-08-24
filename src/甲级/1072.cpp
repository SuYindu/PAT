#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, k, d;
const int N = 1020;
int graph[N][N];

int id(string str) {
    if (str.front() == 'G') 
        return stoi(str.substr(1)) + n;
    return stoi(str);
}

struct Result {
    bool valid;
    int min_dist;
    double avg_dist;

    friend bool better(Result a, Result b) {
        if (a.valid    != b.valid)    return a.valid    > b.valid;
        if (a.min_dist != b.min_dist) return a.min_dist > b.min_dist;
        return a.avg_dist < b.avg_dist;
    }
};

Result dijkstra(int src) {
    vector<bool> mark(N);
    vector<int> dist(N, INF);
    dist[src] = 0;

    while (true) {
        int v = n + m + 1;
        for (int w = 1; w <= n + m; w++)
            if (!mark[w] && dist[w] < dist[v])
                v = w;
        if (v == n + m + 1) break;

        mark[v] = true;
        for (int w = 1; w <= n + m; w++) {
            if (!graph[v][w] || mark[w]) continue;
            dist[w] = min(dist[v] + graph[v][w], dist[w]);
        }
    }
    Result result{true, INF, 0};
    for (int v = 1; v <= n; v++) {
        if (dist[v] > d) result.valid = false;
        result.min_dist = min(dist[v], result.min_dist);
        result.avg_dist += (double)dist[v] / n;
    }
    return result;
}

int main() {
    cin >> n >> m >> k >> d;
    while (k--) {
        string s1, s2;
        cin >> s1 >> s2;
        int v = id(s1), w = id(s2);
        cin >> graph[v][w];
        graph[w][v] = graph[v][w];
    }
    int ans = -1;
    Result best{true, 0, 0};
    for (int v = n + 1; v <= n + m; v++) {
        Result result = dijkstra(v);
        if (better(result, best)) {
            ans = v;
            best = result;
        }
    }
    if (ans == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n", ans - n);
        printf("%.1f %.1f\n", (double)best.min_dist, best.avg_dist);
    }
    return 0;
}