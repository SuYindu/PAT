#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double num, sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &num);
        sum += num * i * (n - i + 1);
    }
    printf("%.2f\n", sum);
    return 0;
}