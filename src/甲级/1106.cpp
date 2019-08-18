#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;
int min_depth = MAX_N, min_count;
vector<int> nodes[MAX_N];

void dfs(int id, int depth) {
    if (nodes[id].empty()) {
        if (depth < min_depth) {
            min_depth = depth;
            min_count = 1;
        } else if (depth == min_depth) {
            min_count++;
        }
    }
    for (auto child : nodes[id])
        dfs(child, depth + 1);
};

int main() {
    int n;
    double p, r;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++) {
        int k, id;
        cin >> k;
        while (k--) {
            cin >> id;
            nodes[i].push_back(id);
        }
    }
    dfs(0, 0);
    printf("%.4f %d\n", p * pow(1 + r / 100, min_depth), min_count);
    return 0;
}