#include <iostream>
#include <vector>
using namespace std;

bool is_max_heap, is_min_heap;

void test_heap(vector<int> &heap, int id, int child) {
    if (child >= heap.size()) return;
    if (heap[child] > heap[id]) is_max_heap = false;
    if (heap[child] < heap[id]) is_min_heap = false;
}

void dfs(int id, vector<int> &heap, vector<int> &ans) {
    if (id >= heap.size()) return;
    int lchild = id * 2 + 1, rchild = id * 2 + 2;
    test_heap(heap, id, lchild);
    test_heap(heap, id, rchild);
    dfs(lchild, heap, ans);
    dfs(rchild, heap, ans);
    ans.push_back(heap[id]);
}

int main() {
    int m, n;
    cin >> m >> n;
    while (m--) {
        vector<int> heap(n), ans;
        for (int i = 0; i < n; i++)
            cin >> heap[i];
        is_max_heap = is_min_heap = true;
        dfs(0, heap, ans);
        cout << (is_max_heap ? "Max Heap" : is_min_heap ? "Min Heap" : "Not Heap") << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}