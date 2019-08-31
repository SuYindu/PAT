#include <iostream>
#include <vector>
using namespace std;

const int N = 505;
vector<int> graph[N];

bool mark[N];
void dfs(int v) {
    mark[v] = true;
    for (auto w : graph[v])
        if (!mark[w]) dfs(w);
}

bool is_connected(int n) {
    dfs(1);
    for (int v = 1; v <= n; v++)
        if (!mark[v]) return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }
    int count = 0;
    for (int v = 1; v <= n; v++) {
        count += graph[v].size() & 1;
        cout << graph[v].size() << (v < n ? ' ' : '\n');
    }
    if (!is_connected(n)) cout << "Non-Eulerian" << endl;
    else if (count == 0)  cout << "Eulerian" << endl;
    else if (count == 2)  cout << "Semi-Eulerian" << endl;
    else                  cout << "Non-Eulerian" << endl;
    return 0;
}