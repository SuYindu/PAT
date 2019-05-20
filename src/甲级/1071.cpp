#include <cctype>
#include <iostream>
#include <map>
using namespace std;

int main() {
    char c;
    string word;
    map<string, int> count;
    while ((c = getchar()) != EOF) {
        if (isalnum(c)) {
            word += tolower(c);
        } else if (!word.empty()) {
            count[word]++;
            word.clear();
        }
    }
    string max;
    for (auto pair : count)
        max = pair.second > count[max] ? pair.first : max;
    cout << max << " " << count[max];
    return 0;
}