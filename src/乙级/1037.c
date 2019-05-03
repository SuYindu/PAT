#include <stdio.h>

#define g2k (17 * 29)
#define s2k 29

int main() {
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int money = g1 * g2k + s1 * s2k + k1;
    int price = g2 * g2k + s2 * s2k + k2;
    int change = price - money;
    if (change < 0) {
        printf("-");
        change *= -1;
    }
    printf("%d.%d.%d\n", change / g2k, change % g2k / s2k, change % s2k);
}