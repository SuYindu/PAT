#include <iostream>
#include <deque>
using namespace std;

const int MAXN = 100005;

struct Node {
    int data, next;
} nodes[MAXN];

int main() {
    int n, k, head, addr;
    cin >> head >> n >> k;
    while (n--) cin >> addr >> nodes[addr].data >> nodes[addr].next;
    int ptr = head;
    deque<int> list, temp;
    while (ptr != -1) {
        for (int i = 0; i < k && ptr != -1; i++) {
            temp.push_back(ptr);
            ptr = nodes[ptr].next;
        }
        if (temp.size() != k) break;
        while (!temp.empty()) {
            list.push_back(temp.back());
            temp.pop_back();
        }
    }
    while (!temp.empty()) {
        list.push_back(temp.front());
        temp.pop_front();
    }
    for (int i = 0; i < list.size() - 1; i++)
        printf("%05d %d %05d\n", list[i], nodes[list[i]].data, list[i+1]);
    printf("%05d %d -1\n", list.back(), nodes[list.back()].data);
    return 0;
}