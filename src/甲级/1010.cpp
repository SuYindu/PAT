#include <cctype>
#include <iostream>
#include <string>
using namespace std;

using LL = long long;

LL str2num(const string &str, LL base) {
    LL ans = 0;
    for (auto c : str) {
        LL digit;
        if (isdigit(c)) digit = c - '0';
        if (islower(c)) digit = c - 'a' + 10;
        if (digit >= base) return -1;
        ans = ans * base + digit;
    }
    return ans >= 0 ? ans : __LONG_LONG_MAX__;
}

int main() {
    string str1, str2;
    int tag, radix;
    cin >> str1 >> str2 >> tag >> radix;
    if (tag == 2) swap(str1, str2);
    LL num = str2num(str1, radix);

    LL left = 2, right = num + 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        LL tmp = str2num(str2, mid);
        if (tmp < num)
            left = mid + 1;
        else if (tmp > num)
            right = mid - 1;
        else
            break;
    }
    if (left <= right) cout << mid;
    else               cout << "Impossible";
    return 0;
}