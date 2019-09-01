#include <iostream>
#include <vector>
using namespace std;

const int INF = 100005, N = 100005;

struct ListNode { int data, next; };
int head;
ListNode nodes[N];

vector<int> ans;
void range_search(int lower, int upper) {
    int temp = head;
    while (temp != -1) {
        if (nodes[temp].data >= lower && nodes[temp].data < upper)
            ans.push_back(temp);
        temp = nodes[temp].next;
    }
}

int main() {
    int n, k, addr;
    cin >> head >> n >> k;
    while (n--) cin >> addr >> nodes[addr].data >> nodes[addr].next;
    range_search(-INF, 0);
    range_search(0, k + 1);
    range_search(k + 1, INF);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i], nodes[ans[i]].data, ans[i+1]);
    printf("%05d %d -1\n", ans.back(), nodes[ans.back()].data);
    return 0;
}