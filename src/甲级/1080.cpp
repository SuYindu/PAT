#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    int number;
    int score1;
    int score2;
    int total;
    int rank;
    vector<int> choices;
};

struct School {
    int quota;
    int last;
    vector<int> result;
};

bool cmp(Student a, Student b) {
    return a.total != b.total ? a.total > b.total : a.score1 > b.score1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<School> schools(m);
    vector<Student> students(n);
    for (int i = 0; i < m; i++)
        cin >> schools[i].quota;
    for (int i = 0; i < n; i++) {
        students[i].number = i;
        cin >> students[i].score1 >> students[i].score2;
        students[i].total = students[i].score1 + students[i].score2;
        students[i].choices.resize(k);
        for (int j = 0; j < k; j++)
            cin >> students[i].choices[j];
    }

    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < n; i++)
        students[i].rank = i == 0 ? 1 : 
            cmp(students[i-1], students[i]) ? i + 1 : students[i-1].rank;
    for (auto student : students) {
        for (auto i : student.choices) {
            if (schools[i].result.size() < schools[i].quota || student.rank == schools[i].last) {
                schools[i].result.push_back(student.number);
                schools[i].last = student.rank;
                break;
            }
        }
    }
    
    for (auto school : schools) {
        sort(school.result.begin(), school.result.end());
        for (int i = 0; i < school.result.size(); i++) {
            cout << school.result[i];
            if (i != school.result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}