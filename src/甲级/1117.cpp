#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int, greater<int>> count;
    int n, dist, sum = 0;
    cin >> n;
    while (n--) { cin >> dist; count[dist]++; }
    for (auto pair : count) {
        sum += pair.second; // 累计天数
        if (sum >= pair.first - 1) { cout << pair.first - 1 << endl; break; }
    }
    return 0;
}