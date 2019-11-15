#include <iostream>
#include <vector>
using namespace std;

const int N = 105;
int ans[N];
vector<int> nodes[N];

int max_level;

void dfs(int id, int level) {
    if (nodes[id].empty()) {
        ans[level]++;
        max_level = max(level, max_level);
    }
    for (auto child : nodes[id])
        dfs(child, level + 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int id, k, child;
        cin >> id >> k;
        while (k--) {
            cin >> child;
            nodes[id].push_back(child);
        }
    }
    int root = 1, root_level = 1;
    dfs(root, root_level);
    for (int i = 1; i <= max_level; i++)
        cout << ans[i] << (i < max_level ? ' ' : '\n');
    return 0;
}