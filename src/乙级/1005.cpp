#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, bool> checked;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (auto num : nums) {
        while (num != 1) {
            if (num % 2 == 0) num = num / 2;
            else              num = (3 * num + 1) / 2;
            checked[num] = true;
        }
    }
    vector<int> ans;
    for (auto num : nums)
        if (!checked[num])
            ans.push_back(num);
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i < ans.size() - 1 ? ' ' : '\n');
    return 0;
}