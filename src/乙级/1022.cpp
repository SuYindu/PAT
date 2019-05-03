#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int sum = a + b;
    string result;
    do {
        result += to_string(sum % d);
        sum /= d;
    } while (sum);
    reverse(result.begin(), result.end());
    cout << result << endl;
}