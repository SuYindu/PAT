#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Print(const vector<int> v) {
    const int n = v.size();
    for (int i = 0; i < n; i++)
        printf("%d%c", v[i], i < n - 1 ? ' ' : '\n');
}

bool Equal(const vector<int> &v1, const vector<int> &v2) {
    return equal(v1.begin(), v1.end(), v2.begin(), v2.end());
}

void InsertionSortIterate(vector<int> &v, int &pos) {
    for (int i = pos++; i > 0 && v[i] < v[i-1]; i--)
        swap(v[i], v[i-1]);
}

bool InsertionSort(const vector<int> &init, const vector<int> &part) {
    int pos = 1;
    vector<int> temp(init);
    while (pos < init.size()) {
        InsertionSortIterate(temp, pos);
        if (Equal(temp, part)) {
            InsertionSortIterate(temp, pos);
            printf("Insertion Sort\n");
            Print(temp);
            return true;
        }
    }
    return false;
}

struct BinaryHeap {
    vector<int> heap;
    int n;

    BinaryHeap(const vector<int> &init) : heap(init) {
        n = heap.size();
        for (int i = n / 2; i >= 0; i--) Sink(i);
    }

    bool Empty() { return n == 0; }

    void Sink(int i) {
        while (2 * i + 1 < n) {
            int j = 2 * i + 1;
            if (j + 1 < n && heap[j+1] > heap[j]) j++;
            if (heap[i] > heap[j]) break;
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    void HeapSortIterate() {
        swap(heap[0], heap[--n]);
        Sink(0);
    }
};


bool HeapSort(const vector<int> &init, const vector<int> &part) {
    BinaryHeap pq(init);
    while (!pq.Empty()) {
        pq.HeapSortIterate();
        if (Equal(pq.heap, part)) {
            pq.HeapSortIterate();
            printf("Heap Sort\n");
            Print(pq.heap);
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> init(n), part(n);
    for (int i = 0; i < n; i++) cin >> init[i];
    for (int i = 0; i < n; i++) cin >> part[i];
    if (!InsertionSort(init, part)) HeapSort(init, part);
    return 0;
}