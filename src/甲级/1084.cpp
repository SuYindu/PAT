#include <iostream>
#include <set>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> printed;
    for (int i = 0, j = 0; i < s1.size(); i++, j++) {
        while (s1[i] != s2[j]) {
            char c = toupper(s1[i++]);
            if (!printed.count(c)) cout << c;
            printed.insert(c);
        }
    }
    return 0;
}