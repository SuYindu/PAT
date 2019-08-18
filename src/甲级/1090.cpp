#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;
vector<int> nodes[MAX_N];
int max_depth, max_count;

void dfs(int id, int depth) {
    if (nodes[id].empty()) {
        if (depth > max_depth) {
            max_depth = depth;
            max_count = 1;
        } else if (depth == max_depth) {
            max_count++;
        }
    }
    for (auto child : nodes[id])
        dfs(child, depth + 1);
}

int main() {
    int n, root, parent;
    double p, r;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent == -1) { root = i; continue; }
        nodes[parent].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d\n", p * pow(1 + r / 100, max_depth), max_count);
    return 0;
}