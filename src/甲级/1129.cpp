#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int val, cnt;

    bool operator<(const Node &b) const {
        return cnt != b.cnt ? cnt > b.cnt : val < b.val;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> counts(n + 1);
    set<Node> nodes;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (i != 0) {
            int j = 0;
            printf("%d:", val);
            for (auto it = nodes.begin(); it != nodes.end() && j++ < k; it++)
                printf(" %d", it->val);
            printf("\n");
        }
        auto it = nodes.find(Node{val, counts[val]});
        if (it != nodes.end()) nodes.erase(it);
        counts[val]++;
        nodes.insert(Node{val, counts[val]});
    }
    return 0;
}