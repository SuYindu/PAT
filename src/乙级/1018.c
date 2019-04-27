#include <stdio.h>

int to_number(char c) {
    switch(c) {
        case 'B': return 0;
        case 'C': return 1;
        case 'J': return 2;
        default: return -1;
    }
}

int win(int n1, int n2) {
    return (n1 + 1) % 3 == n2;
}

int main() {
    int n, count[3] = {}, win_count1[3] = {}, win_count2[3] = {};
    scanf("%d", &n);
    while (n--) {
        char c1, c2;
        getchar();
        scanf("%c %c", &c1, &c2);
        int n1 = to_number(c1), n2 = to_number(c2);
        if (win(n1, n2)) {
            count[0]++;
            win_count1[n1]++;
        } else if (win(n2, n1)) {
            count[2]++;
            win_count2[n2]++;
        } else {
            count[1]++;
        }
    }
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < 3; i++) {
        if (win_count1[i] > win_count1[idx1])
            idx1 = i;
        if (win_count2[i] > win_count2[idx2])
            idx2 = i;
    }
    char to_character[3] = {'B', 'C', 'J'};
    printf("%d %d %d\n", count[0], count[1], count[2]);
    printf("%d %d %d\n", count[2], count[1], count[0]);
    printf("%c %c\n", to_character[idx1], to_character[idx2]);
    return 0;
}