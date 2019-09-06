#include <iostream>
#include <vector>
using namespace std;

const int N = 10005;
int ranks[N], checked[N];

bool is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return false;
    return true;
}

int main() {
    int n, k, id;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id;
        ranks[id] = i;
    }
    cin >> k;
    while (k--) {
        cin >> id;
        printf("%04d: ", id);
        if (ranks[id] == 0)           printf("Are you kidding?\n");
        else if (checked[id])         printf("Checked\n");
        else if (ranks[id] == 1)      printf("Mystery Award\n");
        else if (is_prime(ranks[id])) printf("Minion\n");
        else                          printf("Chocolate\n");
        checked[id] = 1;
    }
    return 0;
}