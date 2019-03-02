// 从大往小递归，免去比较序列的麻烦

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int max_sum = 0;
vector<int> pow_cache;
vector<int> solution, best_solution;

void FindSolution(int n, int k, int p, int sum, int index) {
    if (n <= 0 || k <= 0) {
        if (n == 0 && k == 0 && sum > max_sum) {
            best_solution = solution;
            max_sum = sum;
        }
        return;
    }
    for (int i = index; i >= 1; i--) {
        solution.push_back(i);
        FindSolution(n - pow_cache[i], k - 1, p, sum + i, i);
        solution.pop_back();
    }
}

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 0; pow(i, p) <= n; i++)
        pow_cache.push_back(pow(i, p));
    FindSolution(n, k, p, 0, pow_cache.size() - 1);
    if (best_solution.empty()) { printf("Impossible\n"); return 0; }
    printf("%d = ", n);
    for (int i = 0; i < k; i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", best_solution[i], p);
    }
    printf("\n");
    return 0;
}