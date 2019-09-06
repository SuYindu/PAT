#include <iostream>
#include <vector>
using namespace std;

struct UnionFindSet {
    vector<int> id;

    UnionFindSet(int size) : id(size + 1) {
        for (int i = 1; i <= size; i++)
            id[i] = i;
    }

    int find(int x) {
        if (id[x] == x) return x;
        return id[x] = find(id[x]);
    }

    void union_sets(int x, int y) {
        int a = find(x), b = find(y);
        id[a] = b;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

const int N = 10005;
UnionFindSet s(N);

int main() {
    int n, m, k, x, y, num = 0, cnt = 0;
    cin >> n;
    while (n--) {
        cin >> m >> x;
        num = max(x, num);
        while (--m) {
            cin >> y;
            s.union_sets(x, y);
            num = max(y, num);
        }
    }
    for (int i = 1; i <= num; i++)
        cnt += s.id[i] == i;
    cout << cnt << " " << num << endl;
    cin >> k;
    while (k--) {
        cin >> x >> y;
        cout << (s.connected(x, y) ? "Yes" : "No") << endl;
    }
    return 0;
}