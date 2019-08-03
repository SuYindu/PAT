// 注意题目中的输出要求：分两行输出

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    vector<int> ans;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == sorted[i] && nums[i] > max_num)
            ans.push_back(nums[i]);
        max_num = max(nums[i], max_num);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << (i != 0 ? " " : "") << ans[i];
    cout << endl;
    return 0;
}