#include <iostream>
#include <set>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    multiset<char> set1, set2;
    for (auto c : str2) set2.insert(c);
    for (auto c : str1) {
        if (set2.count(c)) {
            set1.insert(c);
            set2.erase(set2.find(c)); // 仅删去第一个元素
        }
    }
    if (set2.empty())
        printf("Yes %lu\n", str1.size() - str2.size());
    else
        printf("No %lu\n", set2.size());
    return 0;
}