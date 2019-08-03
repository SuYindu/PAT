#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), sums(n + 1);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i-1] + nums[i-1];

    int near_sum = sums.back();
    for (auto i = sums.begin(); i != sums.end(); i++) {
        auto j = lower_bound(i + 1, sums.end(), *i + m);
        if (j != sums.end())
            near_sum = min(*j - *i, near_sum);
    }
    for (auto i = sums.begin(); i != sums.end(); i++) {
        auto j = lower_bound(i + 1, sums.end(), *i + near_sum);
        if (j != sums.end() && *j - *i == near_sum)
            printf("%d-%d\n", i - sums.begin() + 1, j - sums.begin());
    }
    return 0;
}