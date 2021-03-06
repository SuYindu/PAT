#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val, next;
};

const int N = 100005;
const int K = 10005;

vector<ListNode> nodes(N);
vector<int> exist(K);

void print_list(vector<int> list) {
    if (list.empty()) return;
    for (int i = 0; i < list.size() - 1; i++)
        printf("%05d %d %05d\n", list[i], nodes[list[i]].val, list[i+1]);
    printf("%05d %d -1\n", list.back(), nodes[list.back()].val);
}

int main() {
    int addr, head, n;
    cin >> head >> n;
    while (n--)
        cin >> addr >> nodes[addr].val >> nodes[addr].next;
    vector<int> list1, list2;
    int temp = head;
    while (temp != -1) {
        if (!exist[abs(nodes[temp].val)])
            list1.push_back(temp);
        else
            list2.push_back(temp);
        exist[abs(nodes[temp].val)] = true;
        temp = nodes[temp].next;
    }
    print_list(list1);
    print_list(list2);
    return 0;
}