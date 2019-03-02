#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct TreeNode {
    string data;
    int left;
    int right;

    friend istream& operator>>(istream &in, TreeNode &node) {
        in >> node.data >> node.left >> node.right;
        return in;
    }
};

void Inorder(int root, const vector<TreeNode> &nodes) {
    if (root == -1)  return;
    if (nodes[root].left == -1 && nodes[root].right == -1) {
        cout << nodes[root].data;
        return;
    }

    cout << '(';
    Inorder(nodes[root].left, nodes);
    cout << nodes[root].data;
    Inorder(nodes[root].right, nodes);
    cout << ')';
}

int FindRoot(const vector<TreeNode> &nodes) {
    set<int> children;
    for (auto node : nodes) {
        children.insert(node.left);
        children.insert(node.right);
    }
    for (int i = 1; i < nodes.size(); i++)
        if (!children.count(i)) return i;
    return 0;
}

void OutputResult(int root, const vector<TreeNode> &nodes) {
    Inorder(nodes[root].left, nodes);
    cout << nodes[root].data;
    Inorder(nodes[root].right, nodes);
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode> nodes(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nodes[i];
    OutputResult(FindRoot(nodes), nodes);
    return 0;
}