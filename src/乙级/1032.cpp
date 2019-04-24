#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    map<int, int> total_score;
    cin >> n;
    while (n--) {
        int id, score;
        cin >> id >> score;
        total_score[id] += score;
    }
    int top = 0, top_id;
    for (auto school : total_score) {
        if (school.second > top) {
            top = school.second;
            top_id = school.first;
        }
    }
    cout << top_id << ' ' << top << endl;
}