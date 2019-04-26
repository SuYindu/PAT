#include <stdio.h>

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while (t--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", ++kase, a + b > c ? "true" : "false");
    }
    return 0;
}