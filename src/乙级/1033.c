#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int invalid[128] = {};
    while ((c = getchar()) != '\n')
        invalid[(int)c] = invalid[tolower(c)] = 1;
    while ((c = getchar()) != EOF) {
        if (invalid[c]) continue;
        if (isupper((int)c) && invalid['+']) continue;
        putchar(c);
    }
    return 0;
}