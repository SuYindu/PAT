#include <iostream>
#include <vector>
using namespace std;

bool IsSolution(vector<int> config) {
    for (int i = 0; i < config.size(); i++)
        for (int j = i + 1; j < config.size(); j++)
            if (config[i] == config[j] || abs(config[j] - config[i]) == j - i)
                return false;
    return true;
}

int main() {
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        vector<int> config(n);
        for (int i = 0; i < n; i++)
            cin >> config[i];
        cout << (IsSolution(config) ? "YES" : "NO") << endl;
    }
    return 0;
}