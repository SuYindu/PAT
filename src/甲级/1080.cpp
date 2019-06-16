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
    vector<int> schools;
};

bool cmp(Student a, Student b) {
    return a.total != b.total ? a.total > b.total : a.score1 > b.score1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int quota[m];
    for (int i = 0; i < m; i++)
        cin >> quota[i];
    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        students[i].number = i;
        cin >> students[i].score1 >> students[i].score2;
        students[i].total = students[i].score1 + students[i].score2;
        students[i].schools.resize(k);
        for (int j = 0; j < k; j++)
            cin >> students[i].schools[j];
    }

    sort(students.begin(), students.end(), cmp);
    for (int i = 0; i < n; i++)
        students[i].rank = i == 0 ? 1 : 
            cmp(students[i-1], students[i]) ? i + 1 : students[i-1].rank;
    vector<int> results[m], last(m);
    for (auto student : students) {
        for (auto school : student.schools) {
            if (results[school].size() < quota[school] || student.rank == last[school]) {
                results[school].push_back(student.number);
                last[school] = student.rank;
                break;
            }
        }
    }
    
    for (auto result : results) {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}