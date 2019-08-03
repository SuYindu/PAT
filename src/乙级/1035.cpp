#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool equal(vector<int> &v1, vector<int> &v2) {
    return equal(v1.begin(), v1.end(), v2.begin(), v2.end());
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << (i < v.size() - 1 ? ' ' : '\n');
}

void insert_iterate(vector<int> &v, int pos) {
    for (int i = pos; i > 0; i--)
        if (v[i-1] > v[i]) swap(v[i], v[i-1]);
}

bool insert_sort(vector<int> &init, vector<int> &part) {
    vector<int> temp(init);
    for (int i = 1; i < init.size(); i++) {
        insert_iterate(temp, i);
        if (equal(temp, part)) {
            insert_iterate(temp, ++i);
            cout << "Insertion Sort" << endl;
            print(temp);
            return true;
        }
    }
    return false;
}

void merge(vector<int> &work, vector<int> &temp, int start1, int start2, int len) {
    int i = start1, j = start2, index = start1, n = work.size();
    while (i - start1 < len && j - start2 < len && i < n && j < n)
        work[index++] = temp[i] < temp[j] ? temp[i++] : temp[j++];
    while (i - start1 < len && i < n) work[index++] = temp[i++];
    while (j - start2 < len && j < n) work[index++] = temp[j++];
}

void merge_iterate(vector<int> &work, vector<int> &temp, int len) {
    copy(work.begin(), work.end(), temp.begin());
    for (int i = 0; i < work.size(); i += 2 * len)
        merge(work, temp, i, i + len, len);
}

bool merge_sort(vector<int> &init, vector<int> &part) {
    vector<int> work(init), temp(init);
    for (int len = 1; len < init.size(); len *= 2) {
        merge_iterate(work, temp, len);
        if (equal(work, part)) {
            merge_iterate(work, temp, len *= 2);
            cout << "Merge Sort" << endl;
            print(work);
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
    if (!insert_sort(init, part)) merge_sort(init, part);
    return 0;
}