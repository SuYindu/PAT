#include <iostream>
using namespace std;

const int E = 1005;
double p1[E], p2[E], res[2 * E];

int main() {
    int k, e, count = 0;
    double c;
    cin >> k;
    while (k--) {
        cin >> e >> c;
        p1[e] = c;
    }
    cin >> k;
    while (k--) {
        cin >> e >> c;
        p2[e] = c;
    }
    for (int i = 0; i < E; i++)
        for (int j = 0; j < E; j++)
            res[i + j] += p1[i] * p2[j];
    for (auto c : res)
        count += (c != 0.0);
    printf("%d", count);
    for (int i = 2 * E - 1; i >= 0; i--)
        if (res[i] != 0.0) printf(" %d %.1f", i, res[i]);
    return 0;
}