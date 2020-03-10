#include <iostream>
#include <queue>
using namespace std;

const int START = 8 * 60, END = 17 * 60;

struct Window {
    queue<int> q;
    int end, free;
};

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    Window windows[n];
    int serve_time[k], ans[k];
    for (int i = 0; i < k; i++) cin >> serve_time[i];
    for (int i = 0; i < n; i++) windows[i].end = START;
    
    int idx = 0;
    while (idx < k) {
        Window &w = windows[idx % n];
        if (w.q.size() >= m) break;
        w.q.push(idx);
        w.end += serve_time[idx];
        w.free = START + serve_time[w.q.front()]; 
        ans[idx++] = w.end;
    }
    while (idx < k) {
        int min = 0;
        for (int i = 0; i < n; i++)
            if (windows[i].free < windows[min].free)
                min = i;
        Window &w = windows[min];
        w.q.pop();
        w.end += serve_time[idx];
        w.free += serve_time[w.q.front()];
        ans[idx++] = w.end;
    }
    while (q--) {
        cin >> idx;
        if (ans[idx - 1] - serve_time[idx - 1] >= END) printf("Sorry\n");
        else printf("%02d:%02d\n", ans[idx - 1] / 60, ans[idx - 1] % 60);
    }
    return 0;
}