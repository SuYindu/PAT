#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
const int N = 205;
int weights[N];
int graph[N][N];

map<string, int> name2id;
map<int, string> id2name;
string name(int id) { return id2name[id]; }
int id(string name) {
    if (!name2id.count(name)) {
        id2name[name2id.size()] = name;
        name2id[name] = name2id.size();
    }
    return name2id[name];
}

vector<int> from[N];
int dijkstra(int src, int dest) {
    vector<bool> mark(N);
    vector<int> dist(N, INF);
    dist[src] = 0;

    while (true) {
        int v = n;
        for (int w = 0; w < n; w++)
            if (!mark[w] && dist[w] < dist[v])
                v = w;
        if (v == dest) break;

        mark[v] = true;
        for (int w = 0; w < n; w++) {
            if (!graph[v][w] || mark[w]) continue;
            if (dist[w] > dist[v] + graph[v][w]) {
                dist[w] = dist[v] + graph[v][w];
                from[w].clear();
                from[w].push_back(v);
            } else if (dist[w] == dist[v] + graph[v][w]) {
                from[w].push_back(v);
            }
        }
    }
    return dist[dest];
}

int max_weight, cnt;
vector<int> tmp, ans;
void dfs(int v) {
    if (from[v].empty()) {
        int weight = 0;
        for (auto w : tmp) weight += weights[w];
        if (weight > max_weight || (weight == max_weight && tmp.size() < ans.size())) {
            max_weight = weight;
            ans = tmp;
        }
        cnt++;
        return;
    }
    
    tmp.push_back(v);
    for (auto w : from[v]) dfs(w);
    tmp.pop_back();
}


int main() {
    string src_name, dest_name = "ROM", temp_name;
    cin >> n >> k >> src_name;
    int src = id(src_name), dest = id(dest_name);
    for (int i = 0; i < n - 1; i++)
        cin >> temp_name >> weights[id(temp_name)];
    for (int i = 0; i < k; i++) {
        string v_name, w_name;
        cin >> v_name >> w_name;
        int v = id(v_name), w = id(w_name);
        cin >> graph[v][w];
        graph[w][v] = graph[v][w];
    }

    int min_dist = dijkstra(src, dest);
    dfs(dest);
    
    printf("%d %d %d %d\n", cnt, min_dist, max_weight, max_weight / (int)ans.size());
    cout << src_name;
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << "->" << name(*it);
    return 0;
}