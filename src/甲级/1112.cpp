#include <iostream>
#include <vector>
using namespace std;

const int ASCII = 128;
vector<bool> stuck(ASCII, true);
vector<bool> marked(ASCII, false);

int main() {
    int k;
    string str;
    cin >> k >> str;
    for (int i = 0, j; i < str.size(); i = j) {
        j = i + 1;
        while (str[j] == str[i] && j - i < k) j++;
        if (j - i != k) stuck[str[i]] = false;
    }
    for (auto c : str) {
        if (stuck[c] && !marked[c]) cout << c;
        marked[c] = true;
    }
    cout << endl;
    for (int i = 0; i < str.size(); i += stuck[str[i]] ? k : 1)
        cout << str[i];
    return 0;
}