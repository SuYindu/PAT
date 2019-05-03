#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n / 100; i++)
        printf("B");
    for (int i = 0; i < n % 100 / 10; i++)
        printf("S");
    for (int i = 1; i <= n % 10; i++)
        printf("%d", i);
    return 0;
}