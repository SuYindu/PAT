#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    m %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + m);
    reverse(nums.begin() + m, nums.end());
    for (int i = 0; i < n; i++)
        cout << nums[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}