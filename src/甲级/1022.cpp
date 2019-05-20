#include <iostream>
#include <set>
#include <map>
using namespace std;

map<string, set<int>> maps[6];

int main() {
    int n, m;
    cin >> n;
    while (n--) {
        int id;
        string title, author, key, publisher, year;
        cin >> id; getchar();
        getline(cin, title);
        maps[1][title].insert(id);
        getline(cin, author);
        maps[2][author].insert(id);
        while (true) {
            char c;
            cin >> key;
            maps[3][key].insert(id);
            if ((c = getchar()) == '\n') break;
        }
        getline(cin, publisher);
        maps[4][publisher].insert(id);
        getline(cin, year);
        maps[5][year].insert(id);
    }
    cin >> m;
    while (m--) {
        int type;
        string key;
        scanf("%d: ", &type);
        getline(cin, key);
        printf("%d: %s\n", type, key.c_str());
        if (maps[type][key].empty()) {
            printf("Not Found\n");
            continue;
        }
        for (auto id : maps[type][key])
            printf("%07d\n", id);
    }
    return 0;
}