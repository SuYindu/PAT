#include <iostream>
#include <string>
using namespace std;

bool judge(int num) {
    string tmp = to_string(num);
    int a = stoi(tmp.substr(0, tmp.size() / 2));
    int b = stoi(tmp.substr(tmp.size() / 2));
    return a * b != 0 && num % (a * b) == 0;
}

int main() {
    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        cout << (judge(num) ? "Yes" : "No") << endl;
    }
    return 0;
}