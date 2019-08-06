#include <iostream>
using namespace std;

int main() {
    int n, to, pos = 0, ans = 0;
    cin >> n;
    while (n--) {
        cin >> to;
        if (to > pos) ans += (to - pos) * 6;
        else          ans += (pos - to) * 4;
        ans += 5;
        pos = to;
    }
    cout << ans << endl;
    return 0;
}