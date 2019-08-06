#include <iostream>
using namespace std;

struct Node {
    bool flag;
    char data;
    int next;
} nodes[100005];

int main() {
    int head1, head2, n;
    scanf("%d%d%d", &head1, &head2, &n);
    while (n--) {
        char data;
        int addr, next;
        scanf("%d %c %d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
    }
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