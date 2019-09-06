#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 205;
bool graph[N][N];
int n, m;

bool judge(const vector<int> &path) {
    if (path.size() != n + 1 || path.front() != path.back()) return false;
    set<int> s;
    for (int i = 0; i < path.size() - 1; i++) {
        if (!graph[path[i]][path[i+1]]) return false;
        s.insert(path[i]);
    }
    return s.size() == n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        graph[v][w] = graph[w][v] = true;
    }
    int k;
    cin >> k;
    while (k--) {
        int l;
        cin >> l;
        vector<int> path(l);
        for (int i = 0; i < l; i++) cin >> path[i];
        cout << (judge(path) ? "YES" : "NO") << endl;
    }
    return 0;
}