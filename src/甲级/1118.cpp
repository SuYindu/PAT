#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 10005;

struct UnionFind {
    vector<int> id;
    vector<int> sz;

    UnionFind(int n) : id(n), sz(n, 1) {
        for (int i = 0; i < n; i++) id[i] = i;
    }

    int Find(int x) {
        if (id[x] == x) return x;
        return id[x] = Find(id[x]);
    }

    void Union(int x, int y) {
        int i = Find(x);
        int j = Find(y);
        if (i == j) return;
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else               { id[j] = i; sz[i] += sz[j]; }
    }

    int Count(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++)
            if (id[i] == i) count++;
        return count;
    }

    bool Connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

int main() {
    int n, m, k, x, y;
    cin >> n;
    set<int> s;
    UnionFind uf(MAXN);
    while (n--) {
        cin >> m;
        cin >> x;
        s.insert(x);
        while (--m) {
            cin >> y;
            s.insert(y);
            uf.Union(x, y);
        }
    }
    cout << uf.Count(s.size()) << " " << s.size() << endl;
    cin >> k;
    while (k--) {
        cin >> x >> y;
        cout << (uf.Connected(x, y) ? "Yes" : "No") << endl;
    }
    return 0;
}