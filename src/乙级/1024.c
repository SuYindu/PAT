#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10000

int main() {
    int i = 0;
    char str[MAXLEN];
    scanf("%s", str);
    while (str[i] != 'E') i++;
    int count = 0, exp = atoi(str + i + 1);
    if (str[0] == '-') putchar('-');
    if (exp > 0) {
        putchar(str[1]);
        for (i = 3; count < exp && str[i] != 'E'; i++) {
            putchar(str[i]);
            count++;
        }
        if (count == exp && str[i] != 'E') {
            putchar('.');
            while (str[i] != 'E') putchar(str[i++]);
        }
        while (count++ < exp) putchar('0');
    } else {
        exp *= -1;
        printf("0.");
        while (count++ < exp - 1) putchar('0');
        for (i = 1; str[i] != 'E'; i++)
            if (str[i] != '.') putchar(str[i]);
    }
    return 0;
}