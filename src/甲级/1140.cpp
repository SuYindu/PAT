#include <iostream>
#include <vector>
using namespace std;

vector<int> LookAndSay(const vector<int> &s) {
    vector<int> result;
    int i = 0, j;
    while (i < s.size()) {
        j = i++;
        while (i < s.size() && s[i] == s[j]) i++;
        result.push_back(s[j]);
        result.push_back(i - j);
    }
    return result;
}

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> result {d};
    while (--n)
        result = LookAndSay(result);
    for (auto digit : result)
        cout << digit;
    cout << endl;
    return 0;
}