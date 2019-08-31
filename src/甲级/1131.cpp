#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N = 10000;
vector<int> graph[N];
map<pair<int, int>, int> lines;

vector<vector<int>> bfs(int src, int dest) {
    vector<bool> mark(N);
    vector<int> dist(N + 1, N);
    vector<vector<int>> path(N);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == dest) break;
        mark[v] = true;
        for (auto w : graph[v]) {
            if (mark[w]) continue;
            if (dist[w] > dist[v] + 1) {
                dist[w] = dist[v] + 1;
                path[w].clear();
                path[w].push_back(v);
                q.push(w);
            } else if (dist[w] == dist[v] + 1) {
                path[w].push_back(v);
            }
        }
    }
    return path;
}

int min_cnt;
vector<int> tmp, ans;
void dfs(vector<vector<int>> &path, int src, int v, int line, int cnt) {
    tmp.push_back(v);
    if (v == src) {
        if (cnt < min_cnt) {
            min_cnt = cnt;
            ans = tmp;
        }
    } else {
        for (auto w : path[v])
            dfs(path, src, w, lines[{v, w}], lines[{v, w}] == line ? cnt : cnt + 1);
    }
    tmp.pop_back();
}

void print() {
    int n = ans.size(), line = lines[{ans[n - 1], ans[n - 2]}], from = ans[n - 1];
    printf("%lu\n", ans.size() - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (lines[{ans[i+1], ans[i]}] != line) {
            printf("Take Line#%d from %04d to %04d.\n", line, from, ans[i+1]);
            line = lines[{ans[i+1], ans[i]}];
            from = ans[i+1];
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", line, from, ans.front());
}

int main() {
    int n, m, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> m >> v;
        while (--m) {
            cin >> w;
            graph[v].push_back(w);
            graph[w].push_back(v);
            lines[{v, w}] = lines[{w, v}] = i;
            v = w;
        }
    }
    cin >> k;
    while (k--) {
        int src, dest;
        cin >> src >> dest;
        auto path = bfs(src, dest);
        min_cnt = N;
        tmp.clear();
        dfs(path, src, dest, 0, 0);
        print();
    }
    return 0;
}