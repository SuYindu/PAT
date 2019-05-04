#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int pos = str.find('E'), exp = stoi(str.substr(pos + 1));
    if (str[0] == '-') cout << '-';
    if (exp > 0) {
        int i, count = 0;
        cout << str[1];
        for (i = 3; count < exp && i < pos; i++) {
            cout << str[i];
            count++;
        }
        if (count == exp && str[i] != 'E')
            cout << '.' << str.substr(i, pos - i);
        else
            while (count++ < exp) cout << 0;
    } else {
        int count = 0;
        exp *= -1;
        cout << "0.";
        while (count++ < exp - 1) cout << 0;
        for (int i = 1; i < pos; i++)
            if (str[i] != '.') cout << str[i];
    }
    return 0;
}