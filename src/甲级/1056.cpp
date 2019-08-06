#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, m, order;
    cin >> n >> m;
    vector<int> weight(n), rank(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> order;
        q.push(order);
    }
    while (q.size() != 1) {
        queue<int> tmp;
        set<int> winners;
        while (!q.empty()) {
            int winner = q.front();
            for (int i = 0; i < m && !q.empty(); i++, q.pop())
                if (weight[q.front()] > weight[winner])
                    winner = q.front();
            winners.insert(winner);
            tmp.push(winner);
        }
        for (int i = 0; i < n; i++)
            if (!winners.count(i) && !rank[i])
                rank[i] = winners.size() + 1;
        q = tmp;
    }
    rank[q.front()] = 1;
    for (int i = 0; i < n; i++)
        cout << rank[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}