#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
struct Node { int addr, data, next; } nodes[N];

int main() {
    int head1, head2, n, addr;
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; i++)
        cin >> addr >> nodes[addr].data >> nodes[addr].next;
    vector<int> list1, list2, ans;
    while (head1 != -1) {
        list1.push_back(head1);
        head1 = nodes[head1].next;
    }
    while (head2 != -1) {
        list2.push_back(head2);
        head2 = nodes[head2].next;
    }
    if (list1.size() < list2.size()) swap(list1, list2);
    reverse(list2.begin(), list2.end());

    int i = 0, j = 0;
    while (j < list2.size()) {
        ans.push_back(list1[i++]);
        ans.push_back(list1[i++]);
        ans.push_back(list2[j++]);
    }
    while (i < list1.size())
        ans.push_back(list1[i++]);

    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i], nodes[ans[i]].data, ans[i+1]);
    printf("%05d %d -1\n", ans.back(), nodes[ans.back()].data);
    return 0;
}