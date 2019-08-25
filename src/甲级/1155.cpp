#include <iostream>
#include <vector>
using namespace std;

vector<int> tree, path;
bool is_max_heap = true, is_min_heap = true;

void dfs(int id) {
    path.push_back(tree[id]);
    if (2 * id + 1 >= tree.size()) {
        for (int i = 0; i < path.size() - 1; i++) {
            if (path[i] < path[i+1]) is_max_heap = false;
            if (path[i] > path[i+1]) is_min_heap = false;
            cout << path[i] << " ";
        }
        cout << path.back() << endl;
    } else {
        if (2 * id + 2 < tree.size()) dfs(2 * id + 2);
        dfs(2 * id + 1);
    }
    path.pop_back();
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) cin >> tree[i];
    dfs(0);
    if      (is_max_heap) cout << "Max Heap" << endl;
    else if (is_min_heap) cout << "Min Heap" << endl;
    else                  cout << "Not Heap" << endl;
    return 0;
}