#include <iostream>
using namespace std;

struct Person {
    string name;
    string birth;
} tmp, max_ans, min_ans;

int main() {
    string upper = "2014/09/06", lower = "1814/09/06";
    max_ans.birth = upper; min_ans.birth = lower;
    int n, count = 0;
    cin >> n;
    while (n--) {
        cin >> tmp.name >> tmp.birth;
        if (tmp.birth < lower || tmp.birth > upper) continue;
        if (tmp.birth < max_ans.birth) max_ans = tmp;
        if (tmp.birth > min_ans.birth) min_ans = tmp;
        count++;
    }
    if (!count)
        cout << count << endl;
    else
        cout << count << ' ' << max_ans.name << ' ' << min_ans.name << endl;
    return 0;
}