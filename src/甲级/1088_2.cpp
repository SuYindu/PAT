// 注意判断符号不要直接用两数相乘

#include <iostream>
using namespace std;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

void Print(long long n, long long d) {
    if (n == 0) { printf("0");   return; }
    if (d == 0) { printf("Inf"); return; }
    int sign1 = n > 0 ? +1 : -1;
    int sign2 = d > 0 ? +1 : -1;
    int sign = sign1 * sign2;
    n = abs(n), d = abs(d);
    int integer = n / d, fraction = n % d;
    if (sign == -1) printf("(-");
    if (fraction == 0) {
        printf("%d", integer);
    } else {
        int factor = GCD(fraction, d);
        if (integer) printf("%d ", integer);
        printf("%d/%d", fraction / factor, (int)d / factor);
    }
    if (sign == -1) printf(")");
}

void Print(long long a, long long b, long long c, long long d, char op) {
    Print(a, b);
    printf(" %c ", op);
    Print(c, d);
    printf(" = ");
    switch(op) {
    case '+': Print(a * d + b * c, b * d); break;
    case '-': Print(a * d - b * c, b * d); break;
    case '*': Print(a * c, b * d);         break;
    case '/': Print(a * d, b * c);         break;
    }
    printf("\n");
}

int main() {
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    Print(a, b, c, d, '+');
    Print(a, b, c, d, '-');
    Print(a, b, c, d, '*');
    Print(a, b, c, d, '/');
    return 0;
}