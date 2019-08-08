#include <stdio.h>

#define MAXN 10005

int visited[MAXN], rank[MAXN];

int is_prime(int num) {
    if (num < 3) return num == 2;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= num / i; i += 2)
        if (num % i == 0) return 0;
    return 1;
}

int main() {
    int n, k, id;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        rank[id] = i + 1;
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (rank[id] == 0)
            printf("Are you kidding?\n");
        else if (visited[id])
            printf("Checked\n");
        else if (rank[id] == 1)
            printf("Mystery Award\n");
        else if (is_prime(rank[id]))
            printf("Minion\n");
        else
            printf("Chocolate\n");
        visited[id] = 1;
    }
    return 0;
}