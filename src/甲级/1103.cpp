// 从大往小递归，免去比较序列的麻烦

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, K, P, max_sum;
vector<int> tmp, ans, cache;

void dfs(int n, int k, int sum, int num) {
    if (n == N && k == K && sum > max_sum) {
        max_sum = sum;
        ans = tmp;
    }
    if (n > N || k > K || num < 1) return;
    
    tmp.push_back(num);
    dfs(n + cache[num], k + 1, sum + num, num);
    tmp.pop_back();
    dfs(n, k, sum, num - 1);
}

int main() {
    cin >> N >> K >> P;
    for (int i = 0; pow(i, P) <= N; i++)
        cache.push_back(pow(i, P));
    dfs(0, 0, 0, cache.size() - 1);
    if (ans.empty()) { printf("Impossible\n"); return 0; }
    printf("%d = %d^%d", N, ans.front(), P);
    for (int i = 1; i < K; i++)
        printf(" + %d^%d", ans[i], P);
    return 0;
}