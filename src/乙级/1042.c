#include <stdio.h>
#include <ctype.h>

#define ALPHA_NUM 26

int main() {
    char c;
    int count[ALPHA_NUM] = {};
    while ((c = getchar()) != EOF)
        if (isalpha(c)) count[tolower(c) - 'a']++;
    int max = 0;
    for (int i = 0; i < ALPHA_NUM; i++)
        max = count[i] > max ? count[i] : max;
    for (int i = 0; i < ALPHA_NUM; i++)
        if (count[i] == max) { printf("%c %d\n", i + 'a', count[i]); break; }
    return 0;
}