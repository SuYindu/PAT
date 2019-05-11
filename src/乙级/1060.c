#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return +1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int miles[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &miles[i]);
    qsort(miles, n, sizeof(int), compare);
    int res = 1;
    while (res <= n && res < miles[res - 1]) res++;
    printf("%d\n", --res);
    return 0;
}