#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake {
    double stock;
    double total_price;
    double unit_price;
};

int main() {
    int n;
    double demand;
    cin >> n >> demand;
    vector<Mooncake> mooncakes(n);
    for (int i = 0; i < n; i++)
        cin >> mooncakes[i].stock;
    for (int i = 0; i < n; i++) {
        cin >> mooncakes[i].total_price;
        mooncakes[i].unit_price = mooncakes[i].total_price / mooncakes[i].stock;
    }
    sort(mooncakes.begin(), mooncakes.end(), [](Mooncake a, Mooncake b) {
        return a.unit_price > b.unit_price;
    });
    double answer = 0.0;
    for (auto mooncake : mooncakes) {
        if (mooncake.stock <= demand) {
            demand -= mooncake.stock;
            answer += mooncake.total_price;
        } else {
            answer += mooncake.unit_price * demand;
            break;
        }
    }
    printf("%.2f", answer);
    return 0;
}