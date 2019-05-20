#include <iostream>
#include <map>
using namespace std;

int main() {
    int m, n, color;
    cin >> m >> n;
    int total = m * n;
    map<int, int> count;
    for (int i = 0; i < total; i++)
        { cin >> color; count[color]++; }
    for (auto pair : count)
        if (pair.second > total / 2)
            cout << pair.first;
    return 0;
}