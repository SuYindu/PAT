#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Person {
    char name[10];
    int age;
    int worth;
};

const int MAXM = 100;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<Person> people(n);
    for (int i = 0; i < n; i++)
        scanf("%s%d%d", people[i].name, &people[i].age, &people[i].worth);
    sort(people.begin(), people.end(), [](Person a, Person b) {
        if (a.worth != b.worth) return a.worth > b.worth;
        if (a.age != b.age)     return a.age < b.age;
        return strcmp(a.name, b.name) < 0;
    });
    // 过滤数据，防止超时
    map<int, int> age_count;
    vector<Person> valid;
    for (auto person : people) {
        if (age_count[person.age] > MAXM) continue;
        valid.push_back(person);
        age_count[person.age]++;
    }
    int kase = 0;
    while (k--) {
        int m, lower, upper;
        scanf("%d%d%d", &m, &lower, &upper);
        vector<Person> result;
        for (auto person : valid) {
            if (result.size() >= m) break;
            if (person.age >= lower && person.age <= upper)
                result.push_back(person);
        }
        printf("Case #%d:\n", ++kase);
        if (result.empty()) {
            printf("None\n");
            continue;
        }
        for (auto person : result)
            printf("%s %d %d\n", person.name, person.age, person.worth);
    }
    return 0;
}