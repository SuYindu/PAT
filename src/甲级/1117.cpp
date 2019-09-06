#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n, greater<int>());
    for (int i = 0; i < n; i++)
        if (i + 1 >= nums[i] - 1) { cout << nums[i] - 1; break; }
    return 0;
}