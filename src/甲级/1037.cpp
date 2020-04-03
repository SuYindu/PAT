#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int coupons[n];
    for (int i = 0; i < n; i++) cin >> coupons[i];
    cin >> m;
    deque<int> products(m);
    for (int i = 0; i < m; i++) cin >> products[i];
    sort(products.begin(), products.end());

    long long ans = 0;
    sort(coupons, coupons + n, less<int>());
    for (auto coupon : coupons) {
        if (coupon >= 0 || products.empty() || products.front() >= 0) break;
        ans += coupon * products.front();
        products.pop_front();
    }
    sort(coupons, coupons + n, greater<int>());
    for (auto coupon : coupons) {
        if (coupon <= 0 || products.empty() || products.back() <= 0) break;
        ans += coupon * products.back();
        products.pop_back();
    }
    cout << ans << endl;
    return 0;
}