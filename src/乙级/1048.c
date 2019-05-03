#include <stdio.h>
#include <string.h>

#define MAXLEN 105

char num2char(int num) {
    if (num < 10) return num + '0';
    switch(num) {
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
        default: return '\0';
    }
}

int main() {
    char a[MAXLEN], b[MAXLEN], res[MAXLEN];
    scanf("%s%s", a, b);
    int n1 = strlen(a), n2 = strlen(b), n = n1 > n2 ? n1 : n2;
    if (n2 > n1) {
        for (int i = n - 1; i >= 0; i--)
            a[i] = a[i + n1 - n];
        memset(a, '0', n - n1);
    } else if (n1 > n2) {
        for (int i = n - 1; i >= 0; i--)
            b[i] = b[i + n2 - n];
        memset(b, '0', n - n2);
    }
    a[n] = b[n] = res[n] = '\0';
    for (int i = n - 1; i >= 0; i--) {
        int code;
        if ((n - i) % 2) code = (a[i] - '0' + b[i] - '0') % 13;
        else             code = (b[i] - a[i] + 10) % 10;
        res[i] = num2char(code);
    }
    printf("%s\n", res);
    return 0;
}