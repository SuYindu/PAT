#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;
bool is_max_heap = true;
bool is_min_heap = true;

void GetPath(int index, vector<int> path) {
    if (index >= heap.size()) return;
    
    path.push_back(heap[index]);
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    // 若该节点为叶节点
    if (left >= heap.size()) {
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << ' ';
            if (path[i] < path[i + 1]) is_max_heap = false;
            if (path[i] > path[i + 1]) is_min_heap = false;
        }
        cout << path.back() << endl;
        return;
    }
    if (right < heap.size())
        GetPath(right, path);
    // if (left < heap.size())
    GetPath(left, path);
}

int main() {
    int n;
    cin >> n;
    heap.resize(n);
    vector<int> path;
    for (int i = 0; i < n; i++)
        cin >> heap[i];
    GetPath(0, path);
    if (is_max_heap)      cout << "Max Heap" << endl;
    else if (is_min_heap) cout << "Min Heap" << endl;
    else                  cout << "Not Heap" << endl;
    return 0;
}