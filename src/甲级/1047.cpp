#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char names[40005][5];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<int>> courses(k+1);
    for (int i = 0; i < n; i++) {
        int m, id;
        scanf("%s %d", &names[i], &m);
        while (m--) {
            scanf("%d", &id);
            courses[id].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        sort(courses[i].begin(), courses[i].end(), [](int a, int b) {
            return strcmp(names[a], names[b]) < 0;
        });
        printf("%d %lu\n", i, courses[i].size());
        for (auto student : courses[i])
            printf("%s\n", names[student]);
    }
    return 0;
}