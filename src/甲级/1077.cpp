#include <iostream>
#include <algorithm>
using namespace std;

const int MAXLEN = 260;

int main() {
    int n;
    size_t min_len = MAXLEN;
    cin >> n; getchar();
    string lines[n];
    for (int i = 0; i < n; i++) {
        getline(cin, lines[i]);
        reverse(lines[i].begin(), lines[i].end());
        min_len = min(lines[i].length(), min_len);
    }
    string answer;
    for (int i = 0; i < min_len; i++) {
        bool flag = true;
        char c = lines[0][i];
        for (int j = 1; j < n && flag; j++)
            if (lines[j][i] != c) flag = false;
        if (!flag) break;
        answer += c;
    }
    reverse(answer.begin(), answer.end());
    cout << (answer.empty() ? "nai" : answer) << endl;
    return 0;
}