#include <iostream>
#include <vector>
using namespace std;

struct Record {
    string name;
    string id;
    int score;

    friend istream& operator>>(istream &in, Record &record) {
        in >> record.name >> record.id >> record.score;
        return in;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Record> records(n);
    for (int i = 0; i < n; i++) cin >> records[i];
    int max = 0, min = 0;
    for (int i = 1; i < n; i++) {
        if (records[i].score > records[max].score) max = i;
        if (records[i].score < records[min].score) min = i;
    }
    cout << records[max].name << ' ' << records[max].id << endl;
    cout << records[min].name << ' ' << records[min].id << endl;
    return 0;
}