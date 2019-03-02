// 注意判断符号不要直接用两数相乘

#include <iostream>
using namespace std;

struct Rational {
    long long n, d;

    int GCD(long long a, long long b) { return b == 0 ? a : GCD(b, a % b); }

    Rational(long long n, long long d) {
        int sign1 = n > 0 ? +1 : -1;
        int sign2 = d > 0 ? +1 : -1;
        int sign = sign1 * sign2;
        n = abs(n); d = abs(d);
        long long factor = GCD(n, d);
        this->n = sign * n / factor;
        this->d = d / factor;
    }

    friend ostream& operator<<(ostream &out, const Rational &num) {
        if (num.n == 0) { out << "0";   return out; }
        if (num.d == 0) { out << "Inf"; return out; }
        
        int integer  = abs(num.n / num.d);
        int fraction = abs(num.n % num.d);
        if (num.n < 0) out << "(-";
        if (integer)   out << integer << (fraction ? " " : "");
        if (fraction)  out << fraction << "/" << num.d;
        if (num.n < 0) out << ")";
        return out;
    }

    friend Rational operator+(Rational a, Rational b) { return Rational(a.n * b.d + a.d * b.n, a.d * b.d); }
    friend Rational operator-(Rational a, Rational b) { return Rational(a.n * b.d - a.d * b.n, a.d * b.d); }
    friend Rational operator*(Rational a, Rational b) { return Rational(a.n * b.n, a.d * b.d); }
    friend Rational operator/(Rational a, Rational b) { return Rational(a.n * b.d, a.d * b.n); }
};

int main() {
    long long na, da, nb, db;
    scanf("%lld/%lld %lld/%lld", &na, &da, &nb, &db);
    Rational a(na, da), b(nb, db);
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}