#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 105, ROOT = 0;

struct TreeNode {
    int weight;
    vector<int> children;
};
TreeNode nodes[MAX_N];

vector<int> path;

void dfs(int id, int sum, int s) {
    if (sum > s) return;

    if (nodes[id].children.empty() && sum == s)
        for (int i = 0; i < path.size(); i++)
            cout << nodes[path[i]].weight << (i < path.size() - 1 ? ' ' : '\n');
    
    for (auto child : nodes[id].children) {
        path.push_back(child);
        dfs(child, sum + nodes[child].weight, s);
        path.pop_back();
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        cin >> nodes[i].weight;
    while (m--) {
        int id, k, child;
        cin >> id >> k;
        while (k--) {
            cin >> child;
            nodes[id].children.push_back(child);
        }
        sort(nodes[id].children.begin(), nodes[id].children.end(), [](int a, int b) {
            return nodes[a].weight > nodes[b].weight;
        });
    }
    path.push_back(ROOT);
    dfs(ROOT, nodes[ROOT].weight, s);
    return 0;
}