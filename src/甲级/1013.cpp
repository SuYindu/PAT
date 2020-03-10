#include <cstring>
#include <iostream>
using namespace std;

int n, m, k;
const int N = 1005;
bool marked[N], graph[N][N];

void dfs(int v, int occupied) {
    marked[v] = true;
    for (int w = 1; w <= n; w++)
        if (graph[v][w] && w != occupied && !marked[w])
            dfs(w, occupied);
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        graph[v][w] = graph[w][v] = true;
    }
    while (k--) {
        int occupied, count = 0;
        scanf("%d", &occupied);
        memset(marked, 0, n + 1);
        for (int v = 1; v <= n; v++) {
            if (marked[v] || v == occupied) continue;
            dfs(v, occupied);
            count++;
        }
        printf("%d\n", count - 1);
    }
    return 0;
}