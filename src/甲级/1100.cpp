#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

const int BASE = 13;

string num2str(int num) {
    static const string digits1[BASE] {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    static const string digits2[BASE] {"    ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    string result;
    if (num / BASE) {
        result = digits2[num / BASE];
        if (num % BASE) result += " " + digits1[num % BASE];
    } else {
        result = digits1[num % BASE];
    }
    return result;
}

int str2num(string str) {
    static map<string, int> nums1 {{"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}, {"tret", 0}};
    static map<string, int> nums2 {{"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6}, {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};
    int result = 0;
    string num;
    stringstream sin(str);
    while (sin >> num)
        result += nums2[num] * BASE + nums1[num];
    return result;
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        string s;
        getline(cin, s);
        if (isdigit(s[0])) cout << num2str(stoi(s)) << endl;
        else               cout << str2num(s) << endl;
    }
    return 0;
}