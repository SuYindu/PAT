#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n, greater<int>());
    for (int i = 0; i < n; i++)
        ans += i < (n + 1) / 2 ? nums[i] : -nums[i];
    printf("%d %d\n", n & 1, ans);
    return 0;
}