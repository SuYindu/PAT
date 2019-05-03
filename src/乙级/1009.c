#include <stdio.h>

int main() {
    int count = 0;
    char words[85][85];
    while ((scanf("%s", words[count])) != EOF)
        count++;
    for (int i = count - 1; i >= 0; i--)
        printf("%s%c", words[i], i > 0 ? ' ' : '\n');
    return 0;
}