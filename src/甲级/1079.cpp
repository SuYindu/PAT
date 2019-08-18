#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;

struct TreeNode {
    int amount;
    vector<int> children;
};
TreeNode nodes[MAX_N];

double p, r, total;

void dfs(int id, int depth) {
    if (nodes[id].children.empty())
        total += nodes[id].amount * p * pow(1 + r / 100, depth);
    for (auto child : nodes[id].children)
        dfs(child, depth + 1);
}

int main() {
    int n;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++) {
        int k, id;
        cin >> k;
        if (k == 0) cin >> nodes[i].amount;
        while (k--) {
            cin >> id;
            nodes[i].children.push_back(id);
        }
    }
    dfs(0, 0);
    printf("%.1f\n", total);
    return 0;
}