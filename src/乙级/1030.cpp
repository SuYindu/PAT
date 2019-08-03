#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (auto i = nums.begin(); i != nums.end(); i++) {
        auto j = upper_bound(nums.begin(), nums.end(), (long long)*i * p);
        ans = max((int)(j - i), ans);
    }
    
    cout << ans << endl;
    return 0;
}