#include <iostream>
using namespace std;

const int MAXE = 1005;
double p1[MAXE], p2[MAXE], res[2*MAXE];

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
    for (int i = 0; i < MAXE; i++)
        for (int j = 0; j < MAXE; j++)
            res[i+j] += p1[i] * p2[j];
    for (auto c : res)
        count += (c != 0.0);
    printf("%d", count);
    for (int i = 2 * MAXE - 1; i >= 0; i--)
        if (res[i] != 0.0) printf(" %d %.1f", i, res[i]);
    return 0;
}