// string 大小写转换：
// transform(str.begin(), str.end(), str.begin(), 
//           [](char c) { return tolower(c); })

// 注意浮点运算的精度丢失

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Testee {
    string id, institution;
    int score;
    double weight;

    friend istream& operator>>(istream &in, Testee &testee) {
        in >> testee.id >> testee.score >> testee.institution;
        string &s = testee.institution;
        transform(s.begin(), s.end(), s.begin(), 
                [](char c) { return tolower(c); });
        switch(testee.id.front()) {
        case 'B': testee.weight = 1.0 / 1.5; break;
        case 'A': testee.weight = 1.0; break;
        case 'T': testee.weight = 1.5; break;
        }
        return in;
    }
};

struct Institution {
    string name;
    int total_score;
    int num_testees;
};

bool Compare(Institution a, Institution b) {
    if (a.total_score != b.total_score)
        return a.total_score > b.total_score;
    else if (a.num_testees != b.num_testees)
        return a.num_testees < b.num_testees;
    else
        return a.name < b.name;
}

void OutputResult(vector<Institution> institutions) {
    cout << institutions.size() << endl;
    int count = 0, rank = 1, last_score = -1;
    for (auto institution : institutions) {
        count++;
        if (institution.total_score != last_score) rank = count;
        cout << rank << " ";
        cout << institution.name << " ";
        cout << institution.total_score << " ";
        cout << institution.num_testees << endl;
        last_score = institution.total_score;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Testee> testees(n);
    vector<Institution> institutions;
    unordered_map<string, double> sum;
    unordered_map<string, int> count;
    for (int i = 0; i < n; i++)
        cin >> testees[i];
    for (auto testee : testees) {
        count[testee.institution]++;
        sum[testee.institution] += testee.score * testee.weight;
    }
    for (auto pair : sum)
        institutions.push_back({pair.first, (int)pair.second, count[pair.first]});
    sort(institutions.begin(), institutions.end(), Compare);
    OutputResult(institutions);
    return 0;
}