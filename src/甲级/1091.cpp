#include <iostream>
#include <queue>
using namespace std;

int m, n, l, t;
int pixels[1300][130][65];
bool marked[1300][130][65];

struct Position {
    int x, y, z;

    friend Position operator+(const Position &a, const Position &b) {
        return Position{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    bool is_legal() {
        if (x >= m || x < 0)  return false;
        if (y >= n || y < 0)  return false;
        if (z >= l || z < 0)  return false;
        if (!pixels[x][y][z]) return false;
        if (marked[x][y][z])  return false;
        return true;        
    }

    void mark() { marked[x][y][z] = true; }
};

Position moves[] {
    Position{+1, 0, 0}, Position{-1, 0, 0},
    Position{0, +1, 0}, Position{0, -1, 0},
    Position{0, 0, +1}, Position{0, 0, -1},
};

int bfs(Position pos) {
    if (!pos.is_legal()) return 0;
    int count = 0;
    queue<Position> q;
    q.push(pos);
    pos.mark();
    while (!q.empty()) {
        Position tmp = q.front(); q.pop();
        count++;
        for (auto move : moves) {
            Position next = tmp + move;
            if (next.is_legal()) {
                q.push(next);
                next.mark();
            }
        }
    }
    return count >= t ? count : 0;
}

int main() {
    cin >> m >> n >> l >> t;
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> pixels[i][j][k];

    int ans = 0;
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += bfs(Position{i, j, k});
    cout << ans << endl;
    return 0;
}