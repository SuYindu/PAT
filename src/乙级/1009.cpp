#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string word;
    vector<string> words;
    while (cin >> word) words.push_back(word);
    reverse(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << (i < words.size() - 1 ? ' ' : '\n');
    return 0;
}