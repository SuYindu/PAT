#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXK = 5;

struct User {
    bool valid;
    int id;
    int total;
    int count;
    int rank;
    vector<int> scores;
};

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    vector<User> users(n);
    for (int i = 0; i < n; i++) {
        users[i].id = i + 1;
        users[i].scores.resize(k, -2);
    }
    int full_marks[k];
    for (int i = 0; i < k; i++)
        scanf("%d", &full_marks[i]);
    while (m--) {
        int uid, pid, score;
        scanf("%d%d%d", &uid, &pid, &score);
        if (score == full_marks[pid-1] && users[uid-1].scores[pid-1] != full_marks[pid-1])
            users[uid-1].count++;
        if (score > users[uid-1].scores[pid-1])
            users[uid-1].scores[pid-1] = score;
    }
    for (auto& user : users) {
        for (auto score : user.scores) {
            if (score >= 0) {
                user.valid = true;
                user.total += score;
            }
        }
    }
    sort(users.begin(), users.end(), [](User a, User b) {
        if (a.total != b.total) return a.total > b.total;
        if (a.count != b.count) return a.count > b.count;
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++) {
        if (!users[i].valid) break;
        users[i].rank = i == 0 ? 1 : users[i].total < users[i-1].total ? i + 1 : users[i-1].rank;
        printf("%d %05d %d", users[i].rank, users[i].id, users[i].total);
        for (auto score : users[i].scores) {
            if (score == -2)      printf(" -"); // 没有提交
            else if (score == -1) printf(" 0"); // 有提交，但未能通过编译
            else                  printf(" %d", score);
        }
        printf("\n");
    }
    return 0;
}