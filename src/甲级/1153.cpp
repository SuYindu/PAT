// 注意 sort 的接口：
// void sort( RandomIt first, RandomIt last, Compare comp );

// 注意 lambda 的用法，例子如下：
    // std::sort(s.begin(), s.end(), [](int a, int b) {
    //     return a > b;   
    // });

// 在数据量较大时使用 printf 输出来加速
// 使用 unordered_set（unordered_map）代替 set（map）来加速
// 对于大参数，使用常量引用来加速

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Testee {
    string card_num;
    char level;
    int score, site, date, num;

    friend istream& operator>>(istream &in, Testee &testee) {
        in >> testee.card_num >> testee.score;
        testee.level = testee.card_num[0];
        testee.site = stoi(testee.card_num.substr(1, 3));
        testee.date = stoi(testee.card_num.substr(4, 6));
        testee.num = stoi(testee.card_num.substr(10, 3));
        return in;
    }
};

void QueryByLevel(char level, const vector<Testee> &testees) {
    vector<Testee> temp;
    for (auto testee : testees)
        if (testee.level == level)
            temp.push_back(testee);
    if (temp.empty()) { printf("NA\n"); return; }
    sort(temp.begin(), temp.end(), [](const Testee &a, const Testee &b) {
        return a.score != b.score ? 
        a.score > b.score : a.card_num < b.card_num;
    });
    for (auto testee : temp)
        printf("%s %d\n", testee.card_num.c_str(), testee.score);
}

void QueryBySite(int site, const vector<Testee> &testees) {
    int count = 0, total_score = 0;
    for (auto testee : testees) {
        if (testee.site == site) {
            count++;
            total_score += testee.score;
        }
    }
    if (count == 0) { printf("NA\n"); return; }
    printf("%d %d\n", count, total_score);
}

struct Site {
    int site, num;
    Site(int site, int num) : site(site), num(num) {}
};

void QueryByDate(int date, const vector<Testee> &testees) {
    unordered_map<int, int> temp;
    for (auto testee : testees)
        if (testee.date == date)
            temp[testee.site]++;
    if (temp.empty()) { printf("NA\n"); return; }
    vector<Site> sites;
    for (auto site : temp)
        sites.push_back(Site(site.first, site.second));
    sort(sites.begin(), sites.end(), [](const Site &a, const Site &b) {
        return a.num != b.num ? 
        a.num > b.num : a.site < b.site;
    });
    for (auto site : sites)
        printf("%d %d\n",site.site, site.num);
}

void Query(int type, string term, const vector<Testee> &testees) {
    switch(type) {
    case 1: QueryByLevel(term.front(), testees); break;
    case 2: QueryBySite(stoi(term), testees); break;
    case 3: QueryByDate(stoi(term), testees); break;
    }
}

int main() {
    int n, m, kase = 0;
    cin >> n >> m;
    vector<Testee> testees(n);
    for (int i = 0; i < n; i++)
        cin >> testees[i];
    while (m--) {
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", ++kase, type, term.c_str());
        Query(type, term, testees);
    }
    return 0;
}