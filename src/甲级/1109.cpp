#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct Person {
    string name;
    int height;
};

vector<Person> people;

void Formate(int &i, int num, deque<string> &q) {
    q.push_back(people[i++].name);
    while (q.size() < num)
        if (q.size() % 2) q.push_front(people[i++].name);
        else              q.push_back (people[i++].name);
}

int main() {
    int n, k;
    cin >> n >> k;
    people.resize(n);
    for (int i = 0; i < n; i++)
        cin >> people[i].name >> people[i].height;
    sort(people.begin(), people.end(), [](Person a, Person b) {
        return a.height != b.height ? a.height > b.height : a.name < b.name;
    });
    int i = 0;
    deque<string> q;
    while (i < n) {
        if (i == 0) Formate(i, n / k + n % k, q);
        else        Formate(i, n / k, q);
        for (int j = 0; j < q.size(); j++)
            cout << q[j] << (j < q.size() - 1 ? ' ' : '\n');
        q.clear();
    }
    return 0;
}