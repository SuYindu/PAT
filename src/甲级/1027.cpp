#include <iostream>
using namespace std;

const int BASE = 13;
const char num2char[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    printf("#%c%c",  num2char[r / BASE], num2char[r % BASE]);
    printf("%c%c",   num2char[g / BASE], num2char[g % BASE]);
    printf("%c%c\n", num2char[b / BASE], num2char[b % BASE]);
    return 0;
}