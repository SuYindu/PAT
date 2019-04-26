#include <iostream>
using namespace std;

int main() {
    char da, db;
    string a, b, pa = "0", pb = "0";
    cin >> a >> da >> b >> db;
    for (auto c : a)
        if (c == da) pa += c;
    for (auto c : b)
        if (c == db) pb += c;
    cout << stoi(pa) + stoi(pb) << endl;
}