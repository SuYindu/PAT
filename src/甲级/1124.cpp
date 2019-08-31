#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    string v[n + 1];
    set<string> s;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = start; i <= n; i += m) {
        while (i <= n && s.count(v[i])) i++;
        if (i > n) break;
        cout << v[i] << endl;
        s.insert(v[i]);
    }
    if (start > n) cout << "Keep going..." << endl;
    return 0;
}