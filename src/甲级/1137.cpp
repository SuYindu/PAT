// 注意不要在要使用 sort 的类型中包含常数
// 原因参见：https://stackoverflow.com/questions/52380025/error-no-matching-function-for-call-to-swap

#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int NO_SCORE = -1;
const int PASSING_SCORE = 60;
const int MIN_ASSIGNMENT_SOCRE = 200;

struct Student {
    string id;
    int assignment_score;
    int midterm_exam_score;
    int final_exam_score;
    int final_score;

    Student(string id, int assignment_score, int midterm_exam_score, int final_exam_score) : 
    id(id), 
    assignment_score(assignment_score), 
    midterm_exam_score(midterm_exam_score), 
    final_exam_score(final_exam_score) {}

    void CalculateFinalScore() {
        if (assignment_score < MIN_ASSIGNMENT_SOCRE || 
        (midterm_exam_score == NO_SCORE && final_exam_score == NO_SCORE)) {
            final_score = NO_SCORE;
        } else if (midterm_exam_score == NO_SCORE) {
            final_score = final_exam_score;
        } else if (final_exam_score == NO_SCORE) {
            final_score = midterm_exam_score * 0.4;
        } else {
            final_score = final_exam_score >= midterm_exam_score ? 
            final_exam_score : round(midterm_exam_score * 0.4 + final_exam_score * 0.6);
        }
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << student.id << " ";
        out << student.assignment_score << " ";
        out << student.midterm_exam_score << " ";
        out << student.final_exam_score << " ";
        out << student.final_score << endl;
        return out;
    }

};

int main() {
    string id;
    vector<Student> students;
    map<string, int> id2index;
    int p, m, n, score;
    cin >> p >> m >> n;
    while (p--) {
        cin >> id >> score;
        students.push_back(Student(id, score, NO_SCORE, NO_SCORE));
        id2index.insert({id, students.size() - 1});
    }
    while (m--) {
        cin >> id >> score;
        if (!id2index.count(id)) {
            students.push_back(Student(id, NO_SCORE, score, NO_SCORE));
            id2index.insert({id, students.size() - 1});
        } else {
            students[id2index[id]].midterm_exam_score = score;
        }
    }
    while (n--) {
        cin >> id >> score;
        if (!id2index.count(id)) {
            students.push_back(Student(id, NO_SCORE, NO_SCORE, score));
            id2index.insert({id, students.size() - 1});
        } else {
            students[id2index[id]].final_exam_score = score;
        }
    }
    for (auto& student : students)
        student.CalculateFinalScore();
    sort(students.begin(), students.end(), [](Student s1, Student s2) {
        return s1.final_score != s2.final_score ? 
        s1.final_score > s2.final_score : s1.id < s2.id;
    });
    for (auto student : students)
        if (student.final_score >= PASSING_SCORE)
            cout << student;
    return 0;
}