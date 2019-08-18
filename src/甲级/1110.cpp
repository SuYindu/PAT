#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
    int left  = -1;
    int right = -1;
};
vector<TreeNode> nodes;

int find_root() {
    set<int> children;
    for (auto node : nodes) {
        children.insert(node.left);
        children.insert(node.right);
    }
    for (int i = 0; i < nodes.size(); i++)
        if (!children.count(i)) return i;
    return -1;
}

int last;
bool is_complete(int root) {
    queue<int> q;
    q.push(root);
    while (true) {
        int temp = q.front(); q.pop();
        if (temp == -1) break;
        q.push(nodes[temp].left);
        q.push(nodes[temp].right);
        last = temp;
    }
    while (!q.empty()) {
        if (q.front() != -1) return false;
        q.pop();
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        if (left  != "-") nodes[i].left  = stoi(left);
        if (right != "-") nodes[i].right = stoi(right);
    }
    int root = find_root();
    if (is_complete(root)) printf("YES %d\n", last);
    else                   printf("NO %d\n" , root);
    return 0;
}