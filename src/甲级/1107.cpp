#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> id, sz;

    UnionFind(int n) : id(n), sz(n, 1) {
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int find(int x) {
        if (id[x] == x) return x;
        return id[x] = find(id[x]);
    }

    void union_sets(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        if (sz[i] >= sz[j]) { id[j] = i; sz[i] += sz[j]; }
        else                { id[i] = j; sz[j] += sz[i]; }
    }

    void print() {
        vector<int> ans;
        for (int i = 0; i < id.size(); i++)
            if (id[i] == i) ans.push_back(sz[i]);
        sort(ans.begin(), ans.end(), greater<int>());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    }
};

const int MAX_H = 1005;

int main() {
    int n, k, h;
    scanf("%d", &n);
    vector<int> hobbies[MAX_H];
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        scanf("%d:", &k);
        while (k--) {
            scanf("%d", &h);
            hobbies[h].push_back(i);
        }
    }
    for (auto hobby : hobbies) {
        if (hobby.empty()) continue;
        for (auto person : hobby)
            uf.union_sets(person, hobby.front());
    }
    uf.print();
    return 0;
}