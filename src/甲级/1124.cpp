#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    string names[n + 1];
    set<string> marked;
    for (int i = 1; i <= n; i++)
        cin >> names[i];
    for (int i = start; i <= n; i += m) {
        while (i <= n && marked.count(names[i])) i++;
        if (i > n) break;
        cout << names[i] << endl;
        marked.insert(names[i]);
    }
    if (start > n) cout << "Keep going..." << endl;
    return 0;
}