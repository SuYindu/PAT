#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    char name[11];
    char id[11];
    int score;
};

int main() {
    int n, lower, upper;
    scanf("%d", &n);
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
        scanf("%s%s%d", students[i].name, students[i].id, &students[i].score);
    scanf("%d%d", &lower, &upper);
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.score > b.score;
    });
    bool found = false;
    for (auto student : students) {
        if (student.score < lower || student.score > upper) continue;
        printf("%s %s\n", student.name, student.id);
        found = true;
    }
    if (!found) printf("NONE\n");
    return 0;
}