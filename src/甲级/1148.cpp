#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> states(n + 1);
    for (int i = 1; i <= n; i++) cin >> states[i];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> liars;
            vector<int> is_wolf(n + 1, 1);
            // 假定 i 和 j 是狼
            is_wolf[i] = is_wolf[j] = -1;
            for (int k = 1; k <= n; k++)
                // 若陈述与假定相悖
                if (states[k] * is_wolf[abs(states[k])] < 0) liars.push_back(k);
            // 若说谎者正好是一人一狼
            if (liars.size() == 2 && is_wolf[liars[0]] + is_wolf[liars[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}