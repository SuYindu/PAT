#include <stdio.h>
#include <math.h>

int main() {
    int n, is_prime[100005];
    scanf("%d", &n);
    for (int i = 2; i < n + 1; i++)
        is_prime[i] = 1;

    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = 0;
    }
    int count = 0;
    for (int i = 3; i <= n - 2; i += 2)
        count += (is_prime[i] && is_prime[i + 2]);
    printf("%d", count);
    return 0;
}