#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFindSet {
    vector<int> id;

    UnionFindSet(int n) : id(n) {
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int find(int x) {
        if (id[x] == x) return x;
        return id[x] = find(id[x]);
    }

    void union_set(int a, int b) {
        int x = find(a), y = find(b);
        if (x != y) id[x] = y;
    }
};

const int N = 1005;
int graph[N][N];

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    while (m--) {
        int v, w, t;
        cin >> v >> w >> t;
        graph[v][w] += t;
    }
    vector<int> evil;
    for (int v = 1; v <= n; v++) {
        int call = 0, back = 0;
        for (int w = 1; w <= n; w++) {
            if (graph[v][w] > 0 && graph[v][w] <= 5) {
                call++;
                back += graph[w][v] > 0;
            }
        }
        if (call > k && back <= 0.2 * call)
            evil.push_back(v);
    }
    UnionFindSet uf(n + 1);
    for (int i = 0; i < evil.size(); i++)
        for (int j = i + 1; j < evil.size(); j++)
            if (graph[evil[i]][evil[j]] && graph[evil[j]][evil[i]])
                uf.union_set(evil[i], evil[j]);
    vector<vector<int>> tmp(n), ans;
    for (auto v : evil)
        tmp[uf.find(v)].push_back(v);
    for (auto gang : tmp)
        if (!gang.empty()) ans.push_back(gang);
    sort(ans.begin(), ans.end(), [](vector<int> a, vector<int> b) {
        return a.front() < b.front();
    });
    for (auto gang : ans)
        for (int i = 0; i < gang.size(); i++)
            cout << gang[i] << (i < gang.size() - 1 ? ' ' : '\n');
    if (ans.empty()) cout << "None" << endl;
    return 0;
}