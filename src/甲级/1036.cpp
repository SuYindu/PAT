#include <iostream>
using namespace std;

struct Student {
    char gender;
    int score;
    string name, id;
} best_girl, worst_boy;

int main() {
    int n;
    cin >> n;
    best_girl.score = -1;
    worst_boy.score = 101;
    while (n--) {
        Student student;
        cin >> student.name >> student.gender >> student.id >> student.score;
        if (student.gender == 'F' && student.score > best_girl.score) best_girl = student;
        if (student.gender == 'M' && student.score < worst_boy.score) worst_boy = student;
    }
    if (best_girl.score == -1)  cout << "Absent" << endl;
    else                        cout << best_girl.name << " " << best_girl.id << endl;
    if (worst_boy.score == 101) cout << "Absent" << endl;
    else                        cout << worst_boy.name << " " << worst_boy.id << endl;
    if (best_girl.score == -1 || worst_boy.score == 101) cout << "NA" << endl;
    else                                                 cout << best_girl.score - worst_boy.score << endl;
    return 0;
}