#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> id;
    vector<int> sz;

    UnionFind(int n) : id(n), sz(n, 1) {
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int Find(int x) {
        if (id[x] == x) return x;
        return id[x] = Find(id[x]);
    }

    void Union(int x, int y) {
        int i = Find(x), j = Find(y);
        if (i == j) return;
        if (sz[i] >= sz[j]) { id[j] = i; sz[i] += sz[j]; }
        else                { id[i] = j; sz[j] += sz[i]; }
    }

    void Output() {
        vector<int> ans;
        for (int i = 0; i < id.size(); i++)
            if (id[i] == i) ans.push_back(sz[i]);
        sort(ans.begin(), ans.end(), greater<int>());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    }
};

const int MAX_HOBBY_NUM = 1005;

int main() {
    int n, k, h;
    scanf("%d", &n);
    vector<int> hobbies[n], people[MAX_HOBBY_NUM];
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        scanf("%d:", &k);
        while (k--) {
            scanf("%d", &h);
            hobbies[i].push_back(h);
            people[h].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
        for (auto hobby : hobbies[i])
            for (auto j : people[hobby])
                uf.Union(i, j);
    uf.Output();
    return 0;
}