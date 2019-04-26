#include <stdio.h>

int main() {
    int n, count_a = 0, count_b = 0;
    scanf("%d", &n);
    while (n--) {
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        int sum = a1 + b1;
        count_a += sum != a2 && sum == b2;
        count_b += sum == a2 && sum != b2;
    }
    printf("%d %d\n", count_a, count_b);
    return 0;
}