// 按边存储线路，DFS + 回朔
// 注意数据输出格式：4 位数字用 %04d 输出

#include <climits>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 10000;
vector<int> graph[MAXN];
map<pair<int, int>, int> line;

int min_count, min_transfer;
vector<bool> visited(MAXN, false);
vector<int> path, best_path;

void Output(int start) {
    printf("%d\n", min_count);
    int last_transfer = start, last_line = 0;
    for (int i = 1; i < best_path.size(); i++) {
        if (line[{best_path[i - 1], best_path[i]}] != last_line) {
            if (last_line != 0) printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, best_path[i - 1]);
            last_line = line[{best_path[i - 1], best_path[i]}];
            last_transfer = best_path[i - 1];
        }
    }
    printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, best_path.back());
}

int Transfer(vector<int> path) {
    int count = 0, last_line = 0;
    for (int i = 1; i < path.size(); i++) {
        if (line[{path[i - 1], path[i]}] != last_line) count++;
        last_line = line[{path[i - 1], path[i]}];
    }
    return count;
}

void DFS(int stop, int count, int dest) {
    if (stop == dest) {
        int transfer = Transfer(path);
        if (count < min_count || (count == min_count && transfer < min_transfer)) {
            min_count = count;
            min_transfer = transfer;
            best_path = path;
        }
        return;
    }
    for (auto next_stop : graph[stop]) {
        if (visited[next_stop]) continue;
        path.push_back(next_stop);
        visited[next_stop] = true;
        DFS(next_stop, count + 1, dest);
        visited[next_stop] = false;
        path.pop_back();
    }
}

void FindBestPath(int start, int dest) {
    min_count = min_transfer = INT_MAX;
    path.clear();
    path.push_back(start);
    visited[start] = true;
    DFS(start, 0, dest);
    visited[start] = false;
    Output(start);
}

int main() {
    int n, m, k;
    cin >> n;
    // 线路从 1 开始编号
    for (int i = 1; i <= n; i++) {
        int stop, last_stop;
        cin >> m >> last_stop;
        for (int j = 1; j < m; j++) {
            cin >> stop;
            graph[last_stop].push_back(stop);
            graph[stop].push_back(last_stop);
            line[{last_stop, stop}] = line[{stop, last_stop}] = i;
            last_stop = stop;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int start, dest;
        cin >> start >> dest;
        FindBestPath(start, dest);
    }
    return 0;
}