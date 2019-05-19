#include <iostream>
using namespace std;

bool is_legal(string s) {
    char temp[100];
    double num;
    sscanf(s.c_str(), "%lf", &num);
    sprintf(temp, "%.2lf", num);
    for (int i = 0; i < s.size(); i++)
        if (temp[i] != s[i]) return false;
    return num <= 1000 && num >= -1000;
}

int main() {
    int n, count = 0;
    double sum = 0.0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (is_legal(s)) { sum += stod(s); count++; }
        else printf("ERROR: %s is not a legal number\n", s.c_str());
    }
    if (count == 0)      printf("The average of 0 numbers is Undefined\n");
    else if (count == 1) printf("The average of 1 number is %.2lf\n", sum);
    else                 printf("The average of %d numbers is %.2lf\n", count, sum / count);
    return 0;
}