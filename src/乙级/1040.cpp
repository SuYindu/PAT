#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int nump = 0, numt = 0, result = 0;
    for (auto c : s) numt += (c == 'T');
    for (auto c : s) {
        switch(c) {
        case 'P' : nump++; break;
        case 'T' : numt--; break;
        case 'A' : result = (result + nump * numt) % 1000000007;
        }
    }
    cout << result;
}