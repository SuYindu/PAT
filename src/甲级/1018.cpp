#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

const int SRC = 0;
const int N = 505;
int weights[N];
int graph[N][N];

vector<int> from[N];

int min_need = INF, min_remain = INF;
vector<int> temp, best;
void dfs(int v) {
    if (v == SRC) {
        int need = 0, remain = 0;
        for (auto it = temp.rbegin(); it != temp.rend(); it++) {
            int weight = weights[*it];
            if (weight > 0) {
                remain += weight;
            } else if (remain > abs(weight)) {
                remain -= abs(weight);
            } else {
                need += abs(weight) - remain;
                remain = 0;
            }
        }
        if (need < min_need || (need == min_need && remain < min_remain)) {
            min_need = need;
            min_remain = remain;
            best = temp;
        }
    }

    temp.push_back(v);
    for (auto w : from[v]) dfs(w);
    temp.pop_back();
}

int main() {
    int n, m, cap, dest;
    cin >> cap >> n >> dest >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
        weights[i] -= cap / 2;
    }
    while (m--) {
        int v, w;
        cin >> v >> w >> graph[v][w];
        graph[w][v] = graph[v][w];
    }

    vector<bool> mark(N);
    vector<int> dist(N, INF);
    dist[SRC] = 0;
    while (true) {
        int v = n + 1;
        for (int w = 0; w <= n; w++)
            if (!mark[w] && dist[w] < dist[v])
                v = w;
        if (v == dest) break;

        mark[v] = true;
        for (int w = 0; w <= n; w++) {
            if (!graph[v][w] || mark[w]) continue;
            if (dist[v] + graph[v][w] < dist[w]) {
                dist[w] = dist[v] + graph[v][w];
                from[w].clear();
                from[w].push_back(v);
            } else if (dist[v] + graph[v][w] == dist[w]) {
                from[w].push_back(v);
            }
        }
    }

    dfs(dest);

    vector<int> path(best.rbegin(), best.rend());
    printf("%d %d", min_need, SRC);
    for (auto v : path) printf("->%d", v);
    printf(" %d\n", min_remain);
    return 0;
}