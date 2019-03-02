#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<string> forwards(n + 1);
    set<string> winners;
    for (int i = 1; i <= n; i++)
        cin >> forwards[i];
    for (int i = s; i <= n; i += m) {
        while (i <= n && winners.count(forwards[i])) i++;
        winners.insert(forwards[i]);
        cout << forwards[i] << endl;
    }
    if (s > n) cout << "Keep going..." << endl;
    return 0;
}