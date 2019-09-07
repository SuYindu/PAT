#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Family {
    int id, count;
    double sets, area;
};

const int N = 10005;
int sets[N], area[N];
Family families[N];

struct UnionFindSet {
    vector<int> id;

    UnionFindSet(int size) : id(size + 1) {
        for (int i = 0; i <= size; i++)
            id[i] = i;
    }

    int find(int f) {
        if (id[f] == f) return f;
        return id[f] = find(id[f]);
    }

    bool connected(int f, int y) {
        return find(f) == find(y);
    }

    void union_sets(int f, int y) {
        int i = find(f), j = find(y);
        if (i < j) id[j] = i;
        else       id[i] = j;
    }
};

int main() {
    int n;
    cin >> n;
    UnionFindSet uf(N);
    while (n--) {
        int id, father, mather, child, k;
        cin >> id >> father >> mather >> k;
        if (father != -1) uf.union_sets(id, father);
        if (mather != -1) uf.union_sets(id, mather);
        while (k--) {
            cin >> child;
            uf.union_sets(id, child);
        }
        cin >> sets[id] >> area[id];
    }
    for (int i = 0; i < N; i++) {
        int id = uf.find(i);
        families[id].id = id;
        families[id].count++;
        families[id].sets += sets[i];
        families[id].area += area[i];
    }
    vector<Family> ans;
    for (auto family : families) {
        if (!family.sets) continue;
        family.sets /= family.count;
        family.area /= family.count;
        ans.push_back(family);
    }
    sort(ans.begin(), ans.end(), [](Family a, Family b) {
        return a.area != b.area ? a.area > b.area : a.id < b.id;
    });
    printf("%lu\n", ans.size());
    for (auto f : ans)
        printf("%04d %d %.3f %.3f\n", f.id, f.count, f.sets, f.area);
    return 0;
}