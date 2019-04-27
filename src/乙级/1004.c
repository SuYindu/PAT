#include <stdio.h>

struct Student {
    char name[11];
    char id[11];
    int score;
} tmp, max, min;

int main() {
    int n;
    scanf("%d", &n);
    max.score = -1;
    min.score = 101;
    while (n--) {
        scanf("%s%s%d", tmp.name, tmp.id, &tmp.score);
        if (tmp.score > max.score) max = tmp;
        if (tmp.score < min.score) min = tmp;
    }
    printf("%s %s\n", max.name, max.id);
    printf("%s %s\n", min.name, min.id);
    return 0;
}