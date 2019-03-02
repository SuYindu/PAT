#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> nums;
    int n, num;
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