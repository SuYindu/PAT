#include <iostream>
#include <set>
using namespace std;

int digit_sum(int num) {
    int res = 0;
    while (num) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    set<int> s;
    int n, num;
    cin >> n;
    while (n--) { 
        cin >> num;
        s.insert(digit_sum(num));
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) cout << ' ';
        cout << *it;
    }
    return 0;
}