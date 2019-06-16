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
<<<<<<< HEAD
    vector<int> choices;
};

struct School {
    int quota;
    int last;
    vector<int> result;
=======
    vector<int> schools;
>>>>>>> a2442b611be898a9453d829db1a600edaed662c4
};

bool cmp(Student a, Student b) {
    return a.total != b.total ? a.total > b.total : a.score1 > b.score1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
<<<<<<< HEAD
    vector<School> schools(m);
    vector<Student> students(n);
    for (int i = 0; i < m; i++)
        cin >> schools[i].quota;
=======
    int quota[m];
    for (int i = 0; i < m; i++)
        cin >> quota[i];
    vector<Student> students(n);
>>>>>>> a2442b611be898a9453d829db1a600edaed662c4
    for (int i = 0; i < n; i++) {
        students[i].number = i;
        cin >> students[i].score1 >> students[i].score2;
        students[i].total = students[i].score1 + students[i].score2;
<<<<<<< HEAD
        students[i].choices.resize(k);
        for (int j = 0; j < k; j++)
            cin >> students[i].choices[j];
=======
        students[i].schools.resize(k);
        for (int j = 0; j < k; j++)
            cin >> students[i].schools[j];
>>>>>>> a2442b611be898a9453d829db1a600edaed662c4
    }

    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < n; i++)
        students[i].rank = i == 0 ? 1 : 
            cmp(students[i-1], students[i]) ? i + 1 : students[i-1].rank;
<<<<<<< HEAD
    for (auto student : students) {
        for (auto i : student.choices) {
            if (schools[i].result.size() < schools[i].quota || student.rank == schools[i].last) {
                schools[i].result.push_back(student.number);
                schools[i].last = student.rank;
=======
    vector<int> results[m], last(m);
    for (auto student : students) {
        for (auto school : student.schools) {
            if (results[school].size() < quota[school] || student.rank == last[school]) {
                results[school].push_back(student.number);
                last[school] = student.rank;
>>>>>>> a2442b611be898a9453d829db1a600edaed662c4
                break;
            }
        }
    }
    
<<<<<<< HEAD
    for (auto school : schools) {
        sort(school.result.begin(), school.result.end());
        for (int i = 0; i < school.result.size(); i++) {
            cout << school.result[i];
            if (i != school.result.size() - 1) cout << " ";
=======
    for (auto result : results) {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) cout << " ";
>>>>>>> a2442b611be898a9453d829db1a600edaed662c4
        }
        cout << endl;
    }
    return 0;
}