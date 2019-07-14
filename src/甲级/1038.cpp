#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string nums[n], ans;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n, [](string a, string b) {
        return a + b < b + a;
    });
    for (auto num : nums)
        ans += num;
    while (ans.front() == '0')
        ans.erase(ans.begin());
    cout << (ans.empty() ? "0" : ans) << endl;
    return 0;
}