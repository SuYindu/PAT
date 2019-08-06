#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Rational {
    int n, d;
    
    Rational(int n, int d) {
        int sign1 = n > 0 ? +1 : -1;
        int sign2 = d > 0 ? +1 : -1;
        int sign = sign1 * sign2;
        int factor = gcd(abs(n), abs(d));
        this->n = abs(n) / factor * sign;
        this->d = abs(d) / factor;
    }

    friend void operator+=(Rational &a, const Rational &b) {
        a = Rational(a.n * b.d + a.d * b.n, a.d * b.d);
    }

    friend ostream& operator<<(ostream& out, Rational r) {
        if (r.n == 0) { out << "0"; return out; }
        
        int integer  = r.n / r.d;
        int fraction = r.n % r.d;
        if (integer)  out << integer << (fraction ? " " : "");
        if (fraction) out << fraction << "/" << r.d;
        return out;
    }
};

int main() {
    int m, n, d;
    scanf("%d", &m);
    Rational ans(0, 1);
    while (m--) {
        scanf("%d/%d", &n, &d);
        ans += Rational(n, d);
    }
    cout << ans << endl;
}