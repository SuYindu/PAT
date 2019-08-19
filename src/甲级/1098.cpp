#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(const vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
}

void insertion_sort_pass(vector<int> &v, int &pos) {
    for (int i = pos++; i > 0 && v[i] < v[i-1]; i--)
        swap(v[i], v[i-1]);
}

bool insertion_sort(const vector<int> &init, const vector<int> &part) {
    int pos = 1;
    vector<int> temp(init);
    while (pos < init.size()) {
        insertion_sort_pass(temp, pos);
        if (temp == part) {
            insertion_sort_pass(temp, pos);
            printf("Insertion Sort\n");
            print(temp);
            return true;
        }
    }
    return false;
}

struct BinaryHeap {
    int n;
    vector<int> heap;

    BinaryHeap(const vector<int> &init) : heap(init) {
        n = heap.size();
        for (int i = n / 2; i >= 0; i--) sink(i);
    }

    bool empty() { return n == 0; }

    void sink(int i) {
        while (2 * i + 1 < n) {
            int j = 2 * i + 1;
            if (j + 1 < n && heap[j+1] > heap[j]) j++;
            if (heap[i] > heap[j]) break;
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    void heap_sort_pass() {
        swap(heap[0], heap[--n]);
        sink(0);
    }
};


bool heap_sort(const vector<int> &init, const vector<int> &part) {
    BinaryHeap pq(init);
    while (!pq.empty()) {
        pq.heap_sort_pass();
        if (part == pq.heap) {
            pq.heap_sort_pass();
            printf("Heap Sort\n");
            print(pq.heap);
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
    if (!insertion_sort(init, part)) heap_sort(init, part);
    return 0;
}