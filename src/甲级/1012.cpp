#include <iostream>
#include <algorithm>
using namespace std;

const int COURSE_NUM = 4;
char course_symbol[COURSE_NUM] = { 'A', 'C', 'M', 'E' };

struct Student {
    int id;
    int scores[COURSE_NUM];
} students[2005];
int ranks[1000005][COURSE_NUM];

int course;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> students[i].id;
        for (int j = 1; j < COURSE_NUM; j++) {
            cin >> students[i].scores[j];
            students[i].scores[0] += students[i].scores[j];
        }
    }
    for (course = 0; course < COURSE_NUM; course++) {
        sort(students, students + n, [](Student a, Student b) {
            return a.scores[course] > b.scores[course];
        });
        ranks[students[0].id][course] = 1;
        for (int i = 1; i < n; i++) {
            int cur = students[i].id, pre = students[i-1].id;
            ranks[cur][course] = students[i].scores[course] < students[i-1].scores[course] ? i + 1 : ranks[pre][course];
        }
    }
    while (m--) {
        int id, best = 0;
        cin >> id;
        if (ranks[id][0] == 0) { printf("N/A\n"); continue; }
        for (int i = 1; i < COURSE_NUM; i++)
            if (ranks[id][i] < ranks[id][best]) best = i;
        printf("%d %c\n", ranks[id][best], course_symbol[best]);
    }
    return 0;
}