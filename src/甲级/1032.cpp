#include <iostream>
using namespace std;

struct Node {
    bool flag;
    char data;
    int next;
} nodes[100005];

int main() {
    int head1, head2, n, addr;
    cin >> head1 >> head2 >> n;
    while (n--) cin >> addr >> nodes[addr].data >> nodes[addr].next;
    while (head1 != -1) {
        nodes[head1].flag = true;
        head1 = nodes[head1].next;
    }
    while (head2 != -1) {
        if (nodes[head2].flag) break;
        head2 = nodes[head2].next;
    }
    if (head2 != -1) printf("%05d\n", head2);
    else             printf("-1\n");
}