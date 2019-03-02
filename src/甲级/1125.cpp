#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    double len = v[0];
    for (int i = 1; i < n; i++)
        len = (len + v[i]) / 2;
    cout << (int)len << endl;
    return 0;
}