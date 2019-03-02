// 注意输入树节点的左右孩子时使用 string，避免 bug
// 注意掌握 DFS

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

int FindRoot() {
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
bool IsComplete(int root) {
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
    int root = FindRoot();
    if (IsComplete(root)) printf("YES %d\n", last);
    else                  printf("NO %d\n" , root);
    return 0;
}