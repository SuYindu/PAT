#include <iostream>
using namespace std;

int main() {
    int n, dest, pos = 0, ans = 0;
    cin >> n;
    while (n--) {
        cin >> dest;
        if (dest > pos) ans += (dest - pos) * 6;
        else            ans += (pos - dest) * 4;
        ans += 5;
        pos = dest;
    }
    cout << ans << endl;
    return 0;
}