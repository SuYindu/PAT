#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        count[nums[i]]++;
    }
    bool found = false;
    for (auto num : nums) {
        if (count[num] == 1) {
            cout << num;
            found = true;
            break;
        }
    }
    if (!found) cout << "None";
    return 0;
}