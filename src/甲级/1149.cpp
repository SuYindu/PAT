// 反向查找（遍历不相容的物品对）来防止超时

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    set<pair<int, int>> pairs;
    while (n--) { int a, b; cin >> a >> b; pairs.insert({a, b}); }
    while (m--) {
        bool flag = true;
        cin >> k;
        set<int> goods;
        while (k--) { int good; cin >> good; goods.insert(good); }
        for (auto i = pairs.begin(); i != pairs.end() && flag; i++)
            if (goods.count(i->first) && goods.count(i->second))
                flag = false;
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}