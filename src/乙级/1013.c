#include <stdio.h>

#define MAXN 1000005

int primes[MAXN];
int not_prime[MAXN];

int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);

    while (count < n) {
    for (int i = 2; count < n; i++) {
        if (not_prime[i]) continue;
        for (int j = i * i; j < MAXN; j += i)
            not_prime[j] = 1;
        primes[++count] = i;
      }
    }
    for (int i = m; i <= n; i++)
        printf("%d%c", primes[i], (i - m + 1) % 10 && i != n ? ' ' : '\n');
    return 0;
}