#include <iostream>
#include <set>
using namespace std;

int FriendID(int num) {
    int result = 0;
    while (num != 0) {
        result += num % 10;
        num /= 10;
    }
    return result;
}

int main() {
    set<int> s;
    int n, num;
    cin >> n;
    while (n--) { 
        cin >> num;
        s.insert(FriendID(num));
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) cout << ' ';
        cout << *it;
    }
    cout << endl;
    return 0;
}