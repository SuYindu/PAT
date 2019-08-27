#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
const int N = 205;
bool graph[N][N];

bool is_clique(const vector<int> &clique) {
    for (int i = 0; i < clique.size(); i++)
        for (int j = i + 1; j < clique.size(); j++)
            if (!graph[clique[i]][clique[j]]) return false;
    return true;
}

bool is_max(const vector<int> &clique) {
    set<int> vetices(clique.begin(), clique.end());
    for (int v = 1; v <= n; v++) {
        if (vetices.count(v)) continue;
        bool flag = true;
        for (auto w : clique)
            if (!graph[v][w]) flag = false;
        if (flag) return false;
    }
    return true;
}

int main() {
    int k, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        graph[v][w] = graph[w][v] = true;
    }
    cin >> k;
    while (k--) {
        cin >> l;
        vector<int> clique(l);
        for (int i = 0; i < l; i++)
            cin >> clique[i];
        cout << (!is_clique(clique) ? "Not a Clique" : !is_max(clique) ? "Not Maximal" : "Yes") << endl;
    }
    return 0;
}