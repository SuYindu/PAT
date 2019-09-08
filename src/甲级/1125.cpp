#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    int ans = nums[0];
    for (int i = 1; i < n; i++)
        ans = (ans + nums[i]) / 2;
    cout << ans << endl;
    return 0;
}