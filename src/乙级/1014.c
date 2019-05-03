#include <stdio.h>
#include <ctype.h>

char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
#define MAX_LEN 65

int main() {
    char s1[MAX_LEN], s2[MAX_LEN], s3[MAX_LEN], s4[MAX_LEN];
    scanf("%s%s%s%s", s1, s2, s3, s4);
    int i;
    for (i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            printf("%s ", week[s1[i] - 'A']);
            break;
        }
    }
    for (i++; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) continue;
        if (isdigit(s1[i])) {
            printf("%02d:", s1[i] - '0');
            break;
        } else if (s1[i] >= 'A' && s1[i] <= 'N') {
            printf("%02d:", s1[i] - 'A' + 10);
            break;
        }
    }
    for (i = 0; s3[i] && s4[i]; i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}