#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Client { int arrive, served; };

int convert(int hour, int minute, int second) {
    return hour * 3600 + minute * 60 + second;
}

int main() {
    int n, k, begin = convert(8, 0, 0), end = convert(17, 0, 0);
    scanf("%d%d", &n, &k);
    vector<Client> clients(n);
    vector<int> windows(k, begin);
    for (int i = 0; i < n; i++) {
        int hour, minute, second, served;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &served);
        clients[i].arrive = convert(hour, minute, second);
        clients[i].served = served > 60 ? 3600 : served * 60;
    }
    sort(clients.begin(), clients.end(), [](Client a, Client b) {
        return a.arrive < b.arrive;
    });
    int count = 0, total = 0;
    for (int i = 0; i < n; i++) {
        if (clients[i].arrive > end) break;
        int free = 0;
        for (int j = 0; j < k; j++)
            if (windows[j] < windows[free]) free = j;
        if (windows[free] < clients[i].arrive) {
            windows[free] = clients[i].arrive + clients[i].served;
        } else {
            total += windows[free] - clients[i].arrive;
            windows[free] += clients[i].served;
        }
        count++;
    }
    printf("%.1f\n", (double)total / 60 / count);
    return 0;
}