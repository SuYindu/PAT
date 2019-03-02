// 注意 int 与 string 的相互转换（C++11）
// string -> int: stoi()
// int -> string: to_string()

// 注意题目中的 note：输出有效数字前的 0

#include <iostream>
#include <string>
using namespace std;

struct NumberIterator {
    int l, k, index;
    string num_str;

    NumberIterator() : index(0) { cin >> l >> k >> num_str; }
    bool HasNext() { return index <= l - k; }
    string NextNumberString() { return num_str.substr(index++, k); }
};

bool IsPrime(int x) {
    if (x < 3) return x == 2;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= x / i; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main() {
    string num_str;
    bool found = false;
    NumberIterator num_iter;
    while(num_iter.HasNext() && !found) {
        num_str = num_iter.NextNumberString();
        if (IsPrime(stoi(num_str))) found = true;
    }
    cout << (found ? num_str : "404") << endl;
    return 0;
}