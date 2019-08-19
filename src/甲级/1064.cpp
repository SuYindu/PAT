#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

int n, cnt = 0;
int tree[MAX_N], keys[MAX_N];

void in_order(int idx) {
    if (idx >= n) return;
    in_order(idx * 2 + 1);
    tree[idx] = keys[cnt++];
    in_order(idx * 2 + 2);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    sort(keys, keys + n);
    in_order(0);
    
    for (int i = 0; i < n; i++)
        cout << tree[i] << (i < n - 1 ? ' ' : '\n');
    return 0;
}