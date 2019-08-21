#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex { int id, level; };

const int MAX_N = 1005;
vector<Vertex> graph[MAX_N];

int bfs(int id, int l) {
    int res = 0;
    queue<Vertex> q;
    vector<bool> marked(MAX_N);
    q.push(Vertex{id, 0});
    marked[id] = true;

    while (!q.empty()) {
        Vertex v = q.front(); q.pop();
        if (v.level > l) break;
        for (auto w : graph[v.id]) {
            if (marked[w.id]) continue;
            w.level = v.level + 1;
            q.push(w);
            marked[w.id] = true;
        }
        res++;
    }
    return res - 1; // 转发自己的微博不算数
}

int main() {
    int n, l, m, k, id;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> id;
            graph[id].push_back(Vertex{i, 0});
        }
    }
    cin >> k;
    while (k--) {
        cin >> id;
        cout << bfs(id, l) << endl;
    }
    return 0;
}