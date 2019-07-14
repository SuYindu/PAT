#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct GasStation {
    double price;
    double pos;
};

int main() {
    int n;
    double cap, dest, dist;
    cin >> cap >> dest >> dist >> n;
    vector<GasStation> st(n+1);
    for (int i = 0; i < n; i++)
        cin >> st[i].price >> st[i].pos;
    st[n].price = 0.0; st[n].pos = dest;
    sort(st.begin(), st.end(), [](GasStation a, GasStation b) {
        return a.pos < b.pos;
    });

    if (st.front().pos != 0.0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int idx = 0;
    double ans = 0.0, pos = 0.0, tank = 0.0, limit = cap * dist;
    while (true) {
        bool found = false;
        int next = idx + 1;

        for (int i = idx + 1; i <= n && st[i].pos <= pos + limit; i++) {
            found = true;
            if (st[i].price < st[idx].price) {
                next = i;
                break;
            }
            if (st[i].price < st[next].price)
                next = i;
        }
        if (!found) break;

        double need = (st[next].pos - pos) / dist;
        if (st[next].price < st[idx].price) {
            if (tank < need) {
                ans += (need - tank) * st[idx].price;
                tank = 0.0;
            } else {
                tank -= need;
            }
        } else {
            ans += (cap - tank) * st[idx].price;
            tank = cap - need;
        }
        idx = next;
        pos = st[idx].pos;
    }

    if (pos + limit >= dest)
        printf("%.2f\n", ans);
    else
        printf("The maximum travel distance = %.2f\n", pos + limit);
    return 0;
}