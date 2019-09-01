#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];

    int tmp_sum = 0, max_sum = -1;
    int tmp_begin = 0, max_begin = 0, max_end = n - 1;
    for (int i = 0; i < n; i++) {
        if (tmp_sum < 0) {
            tmp_sum = nums[i];
            tmp_begin = i;
        } else {
            tmp_sum += nums[i];
        }
        if (tmp_sum > max_sum) {
            max_sum = tmp_sum;
            max_begin = tmp_begin;
            max_end = i;
        }
    }
    printf("%d %d %d\n", max_sum > 0 ? max_sum : 0, nums[max_begin], nums[max_end]);
    return 0;
}