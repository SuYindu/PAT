#include <stdio.h>

int main() {
    int n, k, score;
    int count[101] = {};
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &score);
        count[score]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &score);
        printf("%d%c", count[score], i < k - 1 ? ' ' : '\n');
    }
    return 0;
}