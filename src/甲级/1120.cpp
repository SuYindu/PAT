#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    while (n--) {
        string num;
        int sum = 0;
        cin >> num;
        for (auto c : num) sum += c - '0';
        s.insert(sum);
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) cout << ' ';
        cout << *it;
    }
    return 0;
}