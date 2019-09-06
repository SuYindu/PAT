#include <iostream>
#include <stack>
using namespace std;

const int N = 100005;
const int M = 316;

stack<int> s;
int table[N];
int block[M];

void push(int x) {
    s.push(x);
    block[x / M]++;
    table[x]++;
}

void pop() {
    int x = s.top();
    s.pop();
    block[x / M]--;
    table[x]--;
    printf("%d\n", x);
}

void peek_median() {
    int cnt = 0, idx = 0, k = (s.size() + 1) / 2;
    while (cnt + block[idx] < k)
        cnt += block[idx++];
    int num = idx * M;
    while (cnt + table[num] < k)
        cnt += table[num++];
    printf("%d\n", num);
}

int main() {
    int n, key;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Push") {
            cin >> key;
            push(key);
        } else if (op == "Pop") {
            if (s.empty()) printf("Invalid\n");
            else           pop();
        } else if (op == "PeekMedian") {
            if (s.empty()) printf("Invalid\n");
            else           peek_median();
        }
    }
    return 0;
}