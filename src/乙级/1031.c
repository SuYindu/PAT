#include <stdio.h>
#include <ctype.h>

int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check_num[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
    char id[20];
    int n, flag = 1;
    scanf("%d", &n);
    while (n--) {
        int i, sum = 0;
        scanf("%s", id);
        for (i = 0; i < 17; i++) {
            if (!isdigit(id[i])) break;
            sum += weights[i] * (id[i] - '0');
        }
        if (check_num[sum % 11] != id[17] || i != 17) {
            printf("%s\n", id);
            flag = 0;
        }
    }
    if (flag) printf("All passed\n");
    return 0;
}