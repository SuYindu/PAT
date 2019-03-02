// 除法或取模运算之前检查除数是否为零，以避免浮点错误

#include <iostream>
#include <string>
using namespace std;

bool CutInteger(string s) {
    int A = stoi(s.substr(0, s.size() / 2));
    int B = stoi(s.substr(s.size() / 2));
    return A * B != 0 && stoi(s) % (A * B) == 0;
}

int main() {
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        cout << (CutInteger(s) ? "Yes" : "No") << endl;
    }
    return 0;
}