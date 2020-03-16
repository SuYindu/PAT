#include <iostream>
using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    scanf("%d", &m);
    int j = 0, count = 0, median = (n + m + 1) / 2;
    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        while (j < n && temp > nums[j]) {
            if (++count == median) cout << nums[j];
            j++;
        }
        if (++count == median) cout << temp;
    }
    while (count < median) {
        if (++count == median) cout << nums[j];
        j++;
    }
    return 0;
}