#include <stdio.h>
#include <stdlib.h>

int total_char(int row) { return (row * row + 2 * row - 1) / 2; }

int main() {
    char c;
    int n, row;
    scanf("%d %c", &n, &c);
    for (row = 1; total_char(row + 2) <= n; row += 2);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row / 2 - abs(i - row / 2); j++)
            putchar(' ');
        for (int j = 0; j < abs(row - 1 - 2 * i) + 1; j++)
            putchar(c);
        putchar('\n');
    }
    printf("%d\n", n - total_char(row));
}