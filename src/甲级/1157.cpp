#include <iostream>
#include <unordered_set>
using namespace std;

string find_min(const unordered_set<string> &s) {
    string res = *s.begin();
    for (auto id : s)
        if (id.substr(6, 8) < res.substr(6, 8))
            res = id;
    return res;
}

int main() {
    int n, m;
    string id;
    unordered_set<string> s1, s2;

    cin >> n;
    while (n--) {
        cin >> id;
        s1.insert(id);
    }
    cin >> m;
    while (m--) {
        cin >> id;
        s2.insert(id);
    }

    int count = 0;
    for (auto id : s2) count += s1.count(id);
    cout << count << endl;
    cout << (count ? find_min(s1) : find_min(s2)) << endl;
    return 0;
}