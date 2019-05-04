#include <iostream>
using namespace std;

string spells[] = {
    "zero", "one", "two", "three", "four", 
    "five", "six", "seven", "eight", "nine"
};

int main() {
    int sum = 0;
    string num;
    cin >> num;
    for (auto c : num) sum += c - '0';
    string digits = to_string(sum);
    for (int i = 0; i < digits.size(); i++)
        cout << spells[digits[i] - '0'] << (i < digits.size() - 1 ? ' ' : '\n');
    return 0;
}