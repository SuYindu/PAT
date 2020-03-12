#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 10005;
vector<int> graph[N];
vector<bool> marked(N);

void dfs(int v) {
    marked[v] = true;
    for (auto w : graph[v])
        if (!marked[w]) dfs(w);
}

int max_depth;
void dfs(int v, set<int> &s, int depth = 0) {
    if (depth > max_depth) {
        max_depth = depth;
        s.clear();
        s.insert(v);
    } else if (depth == max_depth) {
        s.insert(v);
    }

    marked[v] = true;
    for (auto w : graph[v])
        if (!marked[w]) dfs(w, s, depth + 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, w;
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    int count = 0;
    fill(marked.begin(), marked.end(), false);
    for (int v = 1; v <= n; v++) {
        if (marked[v]) continue;
        dfs(v);
        count++;
    }
    if (count != 1) {
        printf("Error: %d components\n", count);
        return 0;
    }

    set<int> tmp;
    fill(marked.begin(), marked.end(), false);
    dfs(1, tmp);
    set<int> ans(tmp);
    fill(marked.begin(), marked.end(), false);
    dfs(*ans.begin(), tmp);
    for (auto v : tmp) ans.insert(v);

    for (auto v : ans) printf("%d\n", v);
    return 0;
}