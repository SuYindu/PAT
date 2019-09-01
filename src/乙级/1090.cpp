#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, k, a, b;
    cin >> n >> m;
    set<pair<int, int>> pairs;
    while (n--) {
        cin >> a >> b;
        pairs.insert({a, b});
    }
    while (m--) {
        bool flag = true;
        set<int> s;
        cin >> k;
        while (k--) {
            cin >> a;
            s.insert(a);
        }
        for (auto pair : pairs)
            if (s.count(pair.first) && s.count(pair.second))
                flag = false;
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}