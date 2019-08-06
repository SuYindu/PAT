#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int data, next;
} nodes[100005];

int main() {
    int n, head, addr;
    cin >> n >> head;
    while (n--) cin >> addr >> nodes[addr].data >> nodes[addr].next;
    vector<int> list;
    while (head != -1) {
        list.push_back(head);
        head = nodes[head].next;
    }
    sort(list.begin(), list.end(), [](int a, int b) {
        return nodes[a].data < nodes[b].data;
    });

    if (list.empty()) { printf("0 -1\n"); return 0; }

    printf("%lu %05d\n", list.size(), list.front());
    for (int i = 0; i < list.size() - 1; i++)
        printf("%05d %d %05d\n", list[i], nodes[list[i]].data, list[i+1]);
    printf("%05d %d -1\n", list.back(), nodes[list.back()].data);
    return 0;
}