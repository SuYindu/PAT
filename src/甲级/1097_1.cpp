// 考试时切勿死磕常规解法，可尝试用取巧的办法

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    int next = -1;
};

const int MAXN = 100005;
const int MAXK = 10005;

vector<ListNode> nodes(MAXN);
vector<bool> exist(MAXK, false);

void Print(int head) {
    while (nodes[head].next != -1) {
        printf("%05d %d %05d\n", head, nodes[head].val, nodes[head].next);
        head = nodes[head].next;
    }
    printf("%05d %d -1\n", head, nodes[head].val);
}

int main() {
    int n, head, addr;
    cin >> head >> n;
    while (n--)
        cin >> addr >> nodes[addr].val >> nodes[addr].next;
    int removed_head = -1, removed_tail;
    int temp = head, tail = -1;
    while (temp != -1) {
        if (exist[abs(nodes[temp].val)]) {
            if (removed_head == -1) removed_head = temp;
            else nodes[removed_tail].next = temp;
            removed_tail = temp;
        } else {
            if (tail != -1) nodes[tail].next = temp;
            tail = temp;
        }
        exist[abs(nodes[temp].val)] = true;
        temp = nodes[temp].next;
    }
    nodes[tail].next = -1;
    Print(head);
    if (removed_head != -1) {
        nodes[removed_tail].next = -1;
        Print(removed_head);
    }
    return 0;
}