#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef char Name[5];

int hash_value(Name name) {
    int res = 0;
    for (int i = 0; i < 3; i++)
        res = res * 26 + name[i] - 'A';
    res = res * 10 + name[3] - '0';
    return res;
}

vector<int> students[26 * 26 * 26 * 10 + 1];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    while (k--) {
        int id, m;
        scanf("%d%d", &id, &m);
        while (m--) {
            Name name;
            scanf("%s", name);
            students[hash_value(name)].push_back(id);
        }
    }
    while (n--) {
        Name name;
        scanf("%s", name);
        vector<int> courses = students[hash_value(name)];
        sort(courses.begin(), courses.end());
        printf("%s %lu", name, courses.size());
        for (auto course : courses)
            printf(" %d", course);
        printf("\n");
    }
    return 0;
}