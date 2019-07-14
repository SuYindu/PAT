#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, left = 0;
    cin >> n;
    vector<int> nums(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
        if (nums[i] != i && nums[i] != 0) left++;
    }

    int ans = 0, i = 1;
    while (left > 0) {
        if (pos[0] == 0) {
            while (i < n && pos[i] == i) i++;
            swap(pos[0], pos[i]);
        } else {
            swap(pos[0], pos[pos[0]]);
            left--;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}