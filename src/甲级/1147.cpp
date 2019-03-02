#include <iostream>
#include <vector>
using namespace std;

enum IsHeap { MAX_HEAP, MIN_HEAP, NOT_HEAP };

IsHeap TestHeap(const vector<int> &heap) {
    int flag = heap[0] > heap[1] ? +1 : -1;
    for (int i = 0; i * 2 + 1 < heap.size() && flag; i++) {
        int left = i * 2 + 1, right = i * 2 + 2;
        if (flag == +1 && (heap[i] < heap[left] || right < heap.size() && heap[i] < heap[right]))
            flag = 0;
        if (flag == -1 && (heap[i] > heap[left] || right < heap.size() && heap[i] > heap[right]))
            flag = 0;
    }
    if (flag == 0) return NOT_HEAP;
    return flag == 1 ? MAX_HEAP : MIN_HEAP;
}

void PostOrderTraversal(int index, const vector<int> &heap) {
    if (index >= heap.size()) return;
    PostOrderTraversal(index * 2 + 1, heap);
    PostOrderTraversal(index * 2 + 2, heap);
    cout << heap[index] << (index != 0 ? ' ' : '\n');
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> heap(n);
    while (m--) {
        for (int i = 0; i < n; i++)
            cin >> heap[i];
        switch(TestHeap(heap)) {
        case MAX_HEAP:
            cout << "Max Heap" << endl; break;
        case MIN_HEAP:
            cout << "Min Heap" << endl; break;
        case NOT_HEAP:
            cout << "Not Heap" << endl; break;
        }
        PostOrderTraversal(0, heap);
    }
    return 0;
}