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
        int i = Find(x);
        int j = Find(y);
        if (i == j) return;
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else               { id[j] = i; sz[i] += sz[j]; }
    }
};

struct Family {
    int id, count;
    double num, area;
};

const int MAX_ID = 10005;

int main() {
    UnionFind uf(MAX_ID);
    vector<bool> exist(MAX_ID);
    vector<int> nums(MAX_ID);
    vector<int> areas(MAX_ID);
    int n;
    cin >> n;
    while (n--) {
        int id, dad, mom, k, child;
        cin >> id >> dad >> mom >> k;
        exist[id] = true;
        if (dad != -1) { exist[dad] = true; uf.Union(id, dad); }
        if (mom != -1) { exist[mom] = true; uf.Union(id, mom); }
        while (k--) { cin >> child; exist[child] = true; uf.Union(id, child); }
        cin >> nums[id] >> areas[id];
    }
    vector<Family> result(MAX_ID, {MAX_ID, 0, 0, 0});
    for (int i = 0; i < MAX_ID; i++) {
        if (!exist[i]) continue;
        Family &f = result[uf.Find(i)];
        f.id = min(i, f.id);
        f.count++;
        f.num += nums[i];
        f.area += areas[i];
    }
    int count = 0;
    for (auto &f : result) {
        if (f.count == 0) continue;
        f.num /= f.count;
        f.area /= f.count;
        count++;
    }
    sort(result.begin(), result.end(), [](Family x, Family y) {
        return x.area != y.area ? x.area > y.area : x.id < y.id;
    });
    printf("%d\n", count);
    for (auto f : result) {
        if (f.count == 0) break;
        printf("%04d %d %.3lf %.3lf\n", f.id, f.count, f.num, f.area);
    }
    return 0;
}