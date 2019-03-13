#include <iostream>
using namespace std;

int main() {
    string spells[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi" };
    string nums, temp;
    cin >> nums;
    int sum = 0;
    for (auto c : nums) sum += c - '0';
    temp = to_string(sum);
    for (int i = 0; i < temp.size(); i++)
        cout << spells[temp[i] - '0'] << (i < temp.size() - 1 ? ' ' : '\n');
    return 0;
}