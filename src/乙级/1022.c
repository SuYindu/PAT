#include <stdio.h>

int main() {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    int sum = a + b;
    int result[35], count = 0;
    do {
        result[count++] = sum % d;
        sum /= d;
    } while (sum);
    for (int i = count - 1; i >= 0; i--)
        printf("%d", result[i]);
}