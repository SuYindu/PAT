#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Testee {
    char level;
    int site, id, score;
    string date, number;

    friend istream& operator>>(istream &in, Testee &testee) {
        in >> testee.number >> testee.score;
        testee.level = testee.number.front();
        testee.site = stoi(testee.number.substr(1, 3));
        testee.date = testee.number.substr(4, 6);
        testee.id   = stoi(testee.number.substr(10, 3));
        return in;
    }
};

vector<Testee> testees;

void query_by_level(char level) {
    vector<Testee> result;
    for (auto testee : testees)
        if (testee.level == level)
            result.push_back(testee);

    sort(result.begin(), result.end(), [](Testee a, Testee b) {
        return a.score != b.score ? a.score > b.score : a.number < b.number;
    });
    if (result.empty()) printf("NA\n");
    for (auto testee : result)
        printf("%s %d\n", testee.number.c_str(), testee.score);
}

void query_by_site(int site) {
    int count = 0, total = 0;
    for (auto testee : testees) {
        if (testee.site == site) {
            count++;
            total += testee.score;
        }
    }
    if (count) printf("%d %d\n", count, total);
    else       printf("NA\n");
}

void query_by_date(string date) {
    map<int, int> count;
    for (auto testee : testees)
        if (testee.date == date)
            count[testee.site]++;
    vector<pair<int, int>> result(count.begin(), count.end());
    sort(result.begin(), result.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    });
    
    if (result.empty()) printf("NA\n");
    for (auto site : result)
        printf("%d %d\n", site.first, site.second);
}

void query(int type, string term) {
    switch (type) {
        case 1 : query_by_level(term.front()); break;
        case 2 : query_by_site(stoi(term)); break;
        case 3 : query_by_date(term); break;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    testees.resize(n);
    for (int i = 0; i < n; i++)
        cin >> testees[i];
    for (int i = 1; i <= m; i++) {
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i, type, term.c_str());
        query(type, term);
    }
    return 0;
}