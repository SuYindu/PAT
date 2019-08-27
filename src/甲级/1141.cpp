#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct School {
    int rank, count;
    string name;
    double total;
};

int main() {
    int n;
    cin >> n;
    map<string, School> tmp;
    while (n--) {
        double score;
        string id, name;
        cin >> id >> score >> name;
        for (auto &c : name) c = tolower(c);
        double weight = id[0] == 'B' ? 1.0 / 1.5 : id[0] == 'A' ? 1.0 : 1.5;
        tmp[name].count++;
        tmp[name].name = name;
        tmp[name].total += weight * score;
    }
    vector<School> ans;
    for (auto entry : tmp) {
        entry.second.total = (int)entry.second.total;
        ans.push_back(entry.second);
    }
    sort(ans.begin(), ans.end(), [](School a, School b) {
        if (a.total != b.total) return a.total > b.total;
        if (a.count != b.count) return a.count < b.count;
        return a.name < b.name;
    });
    ans[0].rank = 1;
    for (int i = 1; i < ans.size(); i++)
        ans[i].rank = ans[i].total == ans[i-1].total ? ans[i-1].rank : i + 1;
    printf("%lu\n", ans.size());
    for (auto x : ans)
        printf("%d %s %d %d\n", x.rank, x.name.c_str(), (int)x.total, x.count);
    return 0;
}