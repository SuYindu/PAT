#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    int score;
};

int main() {
    int n, c;
    cin >> n >> c;
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
        cin >> students[i].id >> students[i].name >> students[i].score;
    switch(c) {
    case 1:
        sort(students.begin(), students.end(), [](Student a, Student b) {
            return a.id < b.id;
        });
        break;
    case 2:
        sort(students.begin(), students.end(), [](Student a, Student b) {
            return a.name <= b.name;
        });
        break;
    case 3:
        sort(students.begin(), students.end(), [](Student a, Student b) {
            return a.score != b.score ? a.score <= b.score : a.id < b.id;
        });
        break;
    }
    for (auto student : students)
        printf("%06d %s %d\n", student.id, student.name.c_str(), student.score);
    return 0;
}