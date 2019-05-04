#include <iostream>
using namespace std;

const int g2k = 17 * 29;
const int s2k = 29;

int main() {
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    long long n1 = g1 * g2k + s1 * s2k + k1;
    long long n2 = g2 * g2k + s2 * s2k + k2;
    long long sum = n1 + n2;
    printf("%lld.%lld.%lld\n", sum / g2k, sum % g2k / s2k, sum % s2k);
    return 0;
}