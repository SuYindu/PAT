#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int total_score[n + 1];
    memset(total_score, 0, sizeof(total_score));
    for (int i = 0; i < n; i++) {
        int id, score;
        scanf("%d%d", &id, &score);
        total_score[id] += score;
    }
    int top = 0, top_id;
    for (int i = 1; i <= n; i++) {
        if (total_score[i] > top) {
            top_id = i;
            top = total_score[i];
        }
    }
    printf("%d %d\n", top_id, top);
}