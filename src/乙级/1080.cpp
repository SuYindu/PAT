#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Student {
    string name;
    int assign = -1, mid = -1, final = -1, total = -1;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int score;
    string name;
    map<string, Student> students;
    while (n--) {
        cin >> name >> score;
        students[name].assign = score;
    }
    while (m--) {
        cin >> name >> score;
        students[name].mid = score;
    }
    while (k--) {
        cin >> name >> score;
        students[name].final = score;
    }
    vector<Student> ans;
    for (auto entry : students) {
        Student s = entry.second;
        s.name = entry.first;
        s.total = ((s.mid > s.final ? s.mid * 0.4 + s.final * 0.6 : s.final) + 0.5);
        if (s.assign >= 200 && s.total >= 60) ans.push_back(s);
    }
    sort(ans.begin(), ans.end(), [](Student a, Student b) {
        return a.total != b.total ? a.total > b.total : a.name < b.name;
    });
    for (auto s : ans)
        printf("%s %d %d %d %d\n", s.name.c_str(), s.assign, s.mid, s.final, s.total);
    return 0;
}