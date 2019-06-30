#include <stdio.h>

int main() {
    int count[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &count[i]);
    for (int i = 1; i < 10; i++) {
        if (count[i]) {
            printf("%d", i);
            count[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
        while (count[i]--)
            printf("%d", i);
    return 0;
}