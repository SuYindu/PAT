#include <stdio.h>

int main() {
    int n, team, id, score;
    int total[1005] = {};
    scanf("%d", &n);
    while (n--) {
        scanf("%d-%d %d", &team, &id, &score);
        total[team] += score;
    }
    int max = 0;
    for (int i = 1; i <= 1000; i++)
        max = total[i] > total[max] ? i : max;
    printf("%d %d\n", max, total[max]);
    return 0;
}