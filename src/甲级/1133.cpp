// 使用 vector 的成员函数 front 和 back 来获取头尾元素
// 注意获取容器的元素前检查容器是否非空

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int addr, key, next;

    friend istream& operator>>(istream &in, ListNode &node) {
        in >> node.addr >> node.key >> node.next;
        return in;
    }
};

unordered_map<int, ListNode> list;

ListNode RearrangeList(ListNode head, int k) {
    vector<int> order;
    ListNode temp = head;
    while (temp.addr != -1) {
        if (temp.key < 0) order.push_back(temp.addr);
        temp = list[temp.next];
    }
    temp = head;
    while (temp.addr != -1) {
        if (temp.key >= 0 && temp.key <= k) order.push_back(temp.addr);
        temp = list[temp.next];
    }
    temp = head;
    while (temp.addr != -1) {
        if (temp.key > k) order.push_back(temp.addr);
        temp = list[temp.next];
    }
    temp = list[order.front()];
    for (auto addr : order) {
        temp.next = list[temp.addr].next = addr;
        temp = list[temp.next];
    }
    list[temp.addr].next = -1;
    return list[order.front()];
}

int main() {
    ListNode temp;
    int head_addr, n, k;
    cin >> head_addr >> n >> k;
    while (n--) {
        cin >> temp;
        list[temp.addr] = temp;
    }
    list[-1] = {-1, -1, -1};
    temp = RearrangeList(list[head_addr], k);
    while (temp.next != -1) {
        printf("%05d %d %05d\n", temp.addr, temp.key, temp.next);
        temp = list[temp.next];
    }    
    printf("%05d %d %d\n", temp.addr, temp.key, temp.next);
    return 0;
}