// 注意判断符号不要直接用两数相乘

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(long long n, long long d) {
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
        int factor = gcd(fraction, d);
        if (integer) printf("%d ", integer);
        printf("%d/%d", fraction / factor, (int)d / factor);
    }
    if (sign == -1) printf(")");
}

void print(long long a, long long b, long long c, long long d, char op) {
    print(a, b);
    printf(" %c ", op);
    print(c, d);
    printf(" = ");
    switch(op) {
        case '+': print(a * d + b * c, b * d); break;
        case '-': print(a * d - b * c, b * d); break;
        case '*': print(a * c, b * d);         break;
        case '/': print(a * d, b * c);         break;
    }
    printf("\n");
}

int main() {
    long long a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    print(a, b, c, d, '+');
    print(a, b, c, d, '-');
    print(a, b, c, d, '*');
    print(a, b, c, d, '/');
    return 0;
}