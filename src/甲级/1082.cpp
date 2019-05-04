#include <iostream>
using namespace std;

string digits[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string measure_words[] = { "Ge", "Shi", "Bai", "Qian", "", " Wan", " Yi"};

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling" << endl;
        return 0;
    } else if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    string str = to_string(n);
    int len = str.size();
    for (int left = 0, right = (len + 3) % 4; right < len; right += 4) {
        bool zero_flag = false;
        for (; left <= right; left++) {
            if (str[left] == '0') {
                zero_flag = true;
            } else {
                if (zero_flag) cout << " ling";
                if (left != 0) cout << ' ';
                cout << digits[str[left] - '0'];
                if (left < right) cout << ' ' << measure_words[right - left];
                zero_flag = false;
            }
        }
        cout << measure_words[(len - right) / 4 + 4];
    }
    return 0;
}