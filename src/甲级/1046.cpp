#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, dist;
    scanf("%d", &n);
    vector<int> accumulate_dist(n + 2);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dist);
        // accumulate_dist[n + 1] 为圆环总距离
        accumulate_dist[i + 1] = accumulate_dist[i] + dist;
    }
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        dist = accumulate_dist[b] - accumulate_dist[a];
        printf("%d\n", min(accumulate_dist[n + 1] - dist, dist));
    }
    return 0;
}