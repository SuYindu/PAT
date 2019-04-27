#include <stdio.h>

int main() {
    int c, e, flag = 0;
    while (scanf("%d%d", &c, &e) == 2) {
        if (e == 0) break;
        if (flag) putchar(' ');
        printf("%d %d", c * e, e - 1);
        flag = 1;
    }
    if (!flag) printf("0 0\n");
    return 0;
}