#include <iostream>
using namespace std;

int main() {
    int t, kase = 0;
    cin >> t;
    while (t--) {
        bool greater;
        long long a, b, c;
        cin >> a >> b >> c;
        if (a > 0 && b > 0 && a + b < 0)
            greater = true;
        else if (a < 0 && b < 0 && a + b >= 0)
            greater = false;
        else
            greater = a + b > c;
        printf("Case #%d: %s\n", ++kase, (greater ? "true" : "false"));
    }
    return 0;
}