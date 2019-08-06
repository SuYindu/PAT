#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;
    do {
        string tmp = to_string(num);
        tmp.insert(0, 4 - tmp.size(), '0');
        sort(tmp.begin(), tmp.end(), greater<char>());
        int num1 = stoi(tmp);
        sort(tmp.begin(), tmp.end(), less<char>());
        int num2 = stoi(tmp);
        printf("%04d - %04d = %04d\n", num1, num2, num = num1 - num2);
    } while (num != 6174 && num != 0);
    return 0;
}