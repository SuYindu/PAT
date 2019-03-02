#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;

bool IsPrime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int main() {
    vector<int> visited(MAXN);
    vector<int> rank(MAXN);
    int n, k, id;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        rank[id] = i + 1;
    }
    cin >> k;
    while (k--) {
        cin >> id;
        printf("%04d: ", id);
        if (rank[id] == 0)
            printf("Are you kidding?\n");
        else if (visited[id])
            printf("Checked\n");
        else if (rank[id] == 1)
            printf("Mystery Award\n");
        else if (IsPrime(rank[id]))
            printf("Minion\n");
        else
            printf("Chocolate\n");
        visited[id] = true;
    }
    return 0;
}