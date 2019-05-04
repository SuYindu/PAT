#include <stdio.h>

int new_num(int num, int digit) {
    int sum = 0;
    while (num) {
        if (num % 10 == digit)
            sum = sum * 10 + digit;
        num /= 10;
    }
    return sum;
}

int main() {
    int a, da, b, db;
    scanf("%d%d%d%d", &a, &da, &b, &db);
    printf("%d\n", new_num(a, da) + new_num(b, db));
}