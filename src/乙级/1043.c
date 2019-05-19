#include <stdio.h>

#define LEN 6

int main() {
    char c, str[] = "PATest";
    int count[LEN] = {};
    while ((c = getchar()) != '\n')
        for (int i = 0; i < LEN; i++)
            if (str[i] == c) count[i]++;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < LEN; i++) {
            if (count[i] <= 0) continue;
            putchar(str[i]);
            count[i]--;
            flag = 1;
        }
    }
    return 0;
}