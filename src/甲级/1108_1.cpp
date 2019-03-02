#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsLegal(string s) {
    int i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    while (i < s.size()) {
        if (s[i] == '.') break;
        if (!isdigit(s[i])) return false;
        i++;
    }
    if (s[i] == '.') {
        if (i == 0) return false;
        int count = 0;
        i++;
        while (isdigit(s[i])) { count++; i++; }
        if (count > 2) return false;
    }
    if (i != s.size()) return false;
    double num = stod(s);
    return num <= 1000 && num >= -1000;
}

int main() {
    double sum = 0.0;
    int n, count = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (IsLegal(s)) { sum += stod(s); count++; }
        else printf("ERROR: %s is not a legal number\n", s.c_str());
    }
    if (count == 0)      printf("The average of 0 numbers is Undefined\n");
    else if (count == 1) printf("The average of 1 number is %.2lf\n", sum);
    else                 printf("The average of %d numbers is %.2lf\n", count, sum / count);
    return 0;
}