#include <stdio.h>

int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int count = (double)(c2 - c1) / 100 + 0.5;
    printf("%02d:%02d:%02d\n", count / 3600, count % 3600 / 60, count % 60);
    return 0;
}