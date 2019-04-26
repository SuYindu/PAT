#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, num, sum;
    vector<int> nums[5];
    cin >> n;
    while (n--) {
        cin >> num;
        if (num % 5)
            nums[num % 5].push_back(num);
        else if (num % 2 == 0)
            nums[0].push_back(num);
    }
    // A1
    sum = 0;
    for (auto num : nums[0])
        sum += num & 1 ? 0 : num;
    if (nums[0].empty()) printf("N ");
    else                 printf("%d ", sum);
    // A2
    sum = 0;
    int sign = 1;
    for (auto num : nums[1]) {
        sum += sign * num;
        sign *= -1;
    }
    if (nums[1].empty()) printf("N ");
    else                 printf("%d ", sum);
    // A3
    if (nums[2].empty()) printf("N ");
    else                 printf("%d ", (int)nums[2].size());
    // A4
    sum = 0;
    for (auto num : nums[3])
        sum += num;
    if (nums[3].empty()) printf("N ");
    else                 printf("%.1f ", (double)sum / nums[3].size());
    // A5
    if (nums[4].empty()) printf("N\n");
    else                 printf("%d\n", *max_element(nums[4].begin(), nums[4].end()));
    return 0;
}