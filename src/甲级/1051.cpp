#include <iostream>
#include <stack>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    while (k--) {
        stack<int> s;
        bool valid = true;
        int push_val = 1, pop_val;
        for (int i = 0; i < n; i++) {
            cin >> pop_val;
            while (push_val <= n && (s.empty() || s.top() != pop_val))
                s.push(push_val++);
            if (s.size() > m) valid = false;
            if (!s.empty() && s.top() == pop_val) s.pop();
        }
        cout << (valid && s.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}