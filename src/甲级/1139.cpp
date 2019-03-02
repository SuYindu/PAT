// 注意题目中的 C 和 D 不能是 A 或 B 本人

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 10000;
vector<int> same_sex_friends[MAXN];
set<pair<int, int>> relations;

vector<pair<int, int>> FindFriends(int A, int B) {
    vector<pair<int, int>> result;
    for (auto C : same_sex_friends[A]) {
        if (C == B) continue;
        for (auto D : same_sex_friends[B])
            if (D != A && relations.count({C, D}))
                result.push_back({C, D});
    }
    return result;
}

int main() {
    int a, b;
    int n, m, k;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        int A = abs(a), B = abs(b);
        relations.insert({A, B});
        relations.insert({B, A});
        if (a * b < 0) continue;
        same_sex_friends[A].push_back(B);
        same_sex_friends[B].push_back(A);
    }
    cin >> k;
    while (k--) {
        cin >> a >> b;
        vector<pair<int, int>> result = FindFriends(abs(a), abs(b));
        sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        });
        printf("%d\n", (int)result.size());
        for (auto pair : result)
            printf("%04d %04d\n", pair.first, pair.second);
    }
    return 0;
}