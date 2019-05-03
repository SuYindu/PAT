#include <stdio.h>
#include <string.h>

int main() {
    char spells[][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi" };
    char nums[105];
    scanf("%s", nums);
    int sum = 0, len = strlen(nums);
    for (int i = 0; i < len; i++)
        sum += nums[i] - '0';
    int idx = 0, res[5];
    while (sum) {
        res[idx++] = sum % 10;
        sum /= 10;
    }
    for (int i = idx - 1; i >= 0; i--)
        printf("%s%c", spells[res[i]], i > 0 ? ' ' : '\n');
    return 0;
}