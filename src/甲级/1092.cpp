// 注意包含 multiset 的头文件为 <set>
// 注意 multiset 的 erase 成员函数会删除所有相同的值

#include <iostream>
#include <set>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    multiset<char> s1, s2;
    for (auto c : str2) s2.insert(c);
    for (auto c : str1) {
        if (s2.count(c)) {
            s1.insert(c);
            s2.erase(s2.find(c));
        }
    }
    if (s2.empty())
        printf("Yes %d\n", (int)str1.size() - (int)str2.size());
    else
        printf("No %d\n", (int)s2.size());
    return 0;
}