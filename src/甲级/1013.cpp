#include <iostream>
#include <vector>
using namespace std;

int occupied;
const int MAX_N = 1005;
bool graph[MAX_N][MAX_N];

void dfs(int v, vector<bool> &marked) {
    marked[v] = true;
    for (int w = 1; w < marked.size(); w++)
        if (graph[v][w] && w != occupied && !marked[w])
            dfs(w, marked);
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        graph[v][w] = graph[w][v] = true;
    }
    while (k--) {
        scanf("%d", &occupied);
        int count = 0;
        vector<bool> marked(n + 1);
        for (int v = 1; v <= n; v++) {
            if (marked[v] || v == occupied) continue;
            dfs(v, marked);
            count++;
        }
        printf("%d\n", count - 1);
    }
    return 0;
}