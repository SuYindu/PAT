#include <stdio.h>

int main() {
    int n, m, count = 0;
    scanf("%d%d", &n, &m);
    m %= n;
    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    for (int i = n - m; i < n; i++) {
        printf("%d", nums[i]);
        if (++count < n) printf(" ");
    }
    for (int i = 0; i < n - m; i++) {
        printf("%d", nums[i]);
        if (++count < n) printf(" ");
    }
    return 0;
}