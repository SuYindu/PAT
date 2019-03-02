#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    if (n % 2 == 1) nums.push_back(0); // 补为偶数
    int sum1 = 0, sum2 = 0;
    int m = nums.size();
    for (int i = 0; i < m / 2; i++) sum1 += nums[i];
    for (int i = m / 2; i < m; i++) sum2 += nums[i];
    printf("%d %d\n", n % 2, sum1 - sum2);
    return 0;
}