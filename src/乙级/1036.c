#include <stdio.h>

int main() {
    char c;
    int row, col;
    scanf("%d %c", &col, &c);
    row = (col + 1) / 2;
    for (int i = 0; i < row; i++) {
        printf("%c", c);
        for (int j = 0; j < col - 2; j++)
            printf("%c", i == 0 || i == row - 1 ? c : ' ');
        printf("%c\n", c);
    }
    return 0;
}