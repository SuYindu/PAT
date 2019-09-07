#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct Player { int arrive, train, vip, start; };
struct Table { int vip, cnt, end; };

const int START = 3600 * 8, END = 3600 * 21;
const int N = 10005, M = 105;
Player players[N];
Table tables[M];

int main() {
    int n, m, k, idx = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int hour, minute, second, train;
        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &train, &players[i].vip);
        players[i].arrive = 3600 * hour + 60 * minute + second;
        players[i].train = min(60 * train, 7200);
        players[i].start = END;
    }
    sort(players, players + n, [](Player a, Player b) { return a.arrive < b.arrive; });
    scanf("%d %d", &m, &k);
    while (k--) {
        scanf("%d", &idx);
        tables[idx].vip = 1;
    }
    for (int i = 1; i <= m; i++) tables[i].end = START;

    for (int i = 0, j = 0; i < n && players[i].arrive < END; i++) {
        if (players[i].vip && i < j) continue;
        int pid = i, tid = 1; // 正常情况下分配下一张空闲的球桌给下一位到达的顾客
        for (int k = 1; k <= m; k++)
            if (tables[k].end < tables[tid].end)
                tid = k;
        if (tables[tid].end >= END) break;
        if (tables[tid].vip) {
            for (j = j < i ? i : j; j < n && !players[j].vip; j++);
            if (j < n && players[j].arrive <= tables[tid].end) {
                i--; // i-- 用于补偿 for 循环的递增
                pid = j++; // vip 顾客插队的特殊情况
            }
        } else if (players[i].vip) {
            int vip_tid = idx;
            for (int k = 1; k <= m; k++)
                if (tables[k].vip && tables[k].end < tables[vip_tid].end)
                    vip_tid = k;
            if (tables[vip_tid].vip && tables[vip_tid].end <= players[i].arrive)
                tid = vip_tid; // vip 顾客优先选择空闲的 vip 球桌的特殊情况
        }
        players[pid].start = max(players[pid].arrive, tables[tid].end);
        tables[tid].end = players[pid].start + players[pid].train;
        tables[tid].cnt++;
    }
    
    sort(players, players + n, [](Player a, Player b) { return a.start < b.start; });
    for (int i = 0; i < n && players[i].start < END; i++) {
        int t1 = players[i].arrive, t2 = players[i].start;
        printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
        printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
        printf("%.0f\n", round((t2 - t1) / 60.0));
    }
    for (int i = 1; i <= m; i++)
        printf("%d%c", tables[i].cnt, i < m ? ' ' : '\n');
    return 0;
}