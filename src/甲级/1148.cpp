#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stat[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> stat[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int good = 0, evil = 0;
            for (int k = 1; k <= n; k++) {
                if (stat[k] > 0 && (stat[k] == i || stat[k] == j)) {
                    if (k == i || k == j) evil++;
                    else                  good++;
                }
                if (stat[k] < 0 && -stat[k] != i && -stat[k] != j) {
                    if (k == i || k == j) evil++;
                    else                  good++;
                }
            }
            if (good == 1 && evil == 1) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}