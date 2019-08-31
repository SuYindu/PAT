#include <iostream>
#include <vector>
using namespace std;

bool judge(const vector<int> &pos) {
    for (int i = 0; i < pos.size(); i++)
        for (int j = i + 1; j < pos.size(); j++)
            if (pos[i] == pos[j] || abs(pos[j] - pos[i]) == j - i)
                return false;
    return true;
}

int main() {
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            cin >> pos[i];
        cout << (judge(pos) ? "YES" : "NO") << endl;
    }
    return 0;
}