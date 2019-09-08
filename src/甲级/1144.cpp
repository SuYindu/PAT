#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, num;
    set<int> nums;
    cin >> n;
    while (n--) {
        cin >> num;
        nums.insert(num);
    }
    int ans = 1;
    while (nums.count(ans)) ans++;
    cout << ans << endl;
    return 0;
}