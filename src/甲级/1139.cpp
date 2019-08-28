#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int N = 10000;
set<int> graph[N];

int main() {
    int n, m, k, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        graph[abs(a)].insert(b);
        graph[abs(b)].insert(a);
    }
    cin >> k;
    while (k--) {
        vector<pair<int, int>> ans;
        cin >> a >> b;
        for (auto c : graph[abs(a)]) {
            if (c * a < 0 || c == b) continue;
            for (auto d : graph[abs(c)]) {
                if (d * b < 0 || d == a) continue;
                if (graph[abs(d)].count(b)) ans.push_back({abs(c), abs(d)});
            }
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first != p2.first ? p1.first < p2.first : p1.second < p2.second;
        });
        printf("%lu\n", ans.size());
        for (auto pair : ans)
            printf("%04d %04d\n", pair.first, pair.second);
    }
    return 0;
}