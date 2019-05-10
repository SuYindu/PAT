#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

enum Type { SAGE, NOBLE, FOOL, SMALL };

struct Person {
    int id;
    int virtue, talent, total;
    Type type;
};

int main() {
    int n, lower, upper;
    cin >> n >> lower >> upper;
    vector<Person> people;
    while (n--) {
        Person tmp;
        cin >> tmp.id >> tmp.virtue >> tmp.talent;
        if (tmp.virtue < lower || tmp.talent < lower)
            continue;
        else if (tmp.virtue >= upper && tmp.talent >= upper)
            tmp.type = SAGE;
        else if (tmp.virtue >= upper)
            tmp.type = NOBLE;
        else if (tmp.talent > tmp.virtue)
            tmp.type = SMALL;
        else
            tmp.type = FOOL;
        tmp.total = tmp.virtue + tmp.talent;
        people.push_back(tmp);
    }
    sort(people.begin(), people.end(), [](Person a, Person b) {
        if (a.type   != b.type)   return a.type   < b.type;
        if (a.total  != b.total)  return a.total  > b.total;
        if (a.virtue != b.virtue) return a.virtue > b.virtue;
        return a.id < b.id;
    });
    printf("%lu\n", people.size());
    for (auto person : people)
        printf("%08d %d %d\n", person.id, person.virtue, person.talent);
    return 0;
}