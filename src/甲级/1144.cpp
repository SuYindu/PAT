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
    num = 1;
    while (nums.count(num)) num++;
    cout << num << endl;
    return 0;
}