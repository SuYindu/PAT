#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, coin;
    cin >> n >> m;
    map<int, int> count;
    while (n--) {
        cin >> coin;
        count[coin]++;
    }
    bool found = false;
    for (auto pair : count) {
        coin = pair.first;
        if (count.count(m - coin)) {
            if (coin == m - coin && count[coin] == 1) continue;
            cout << coin << " " << m - coin;
            found = true;
            break;
        }
    }
    if (!found) cout << "No Solution";
    return 0;
}