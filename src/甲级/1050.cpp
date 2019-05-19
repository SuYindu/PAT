#include <iostream>
#include <set>
using namespace std;

int main() {
    string str1, str2, ans;
    getline(cin, str1);
    getline(cin, str2);
    set<char> s;
    for (auto c : str2) s.insert(c);
    for (auto c : str1) if (!s.count(c)) ans += c;
    cout << ans;
    return 0;
}