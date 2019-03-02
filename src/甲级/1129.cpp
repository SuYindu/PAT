// 重载操作符 < 以自定义 set，注意将操作符 < 定义为 const 成员函数
// 输入大量数据时用  scanf 代替 cout 来加速
// 大参数时用引用传递来加速

#include <cstdio>
#include <set>
#include <unordered_map>
using namespace std;

struct Node {
    int index, count;

    bool operator<(const Node &node) const {
        return count != node.count ? count > node.count : index < node.index;
    }
};

void Output(const set<Node> &s, int index, int k) {
    printf("%d:", index);
    int count = 0;
    for (auto it = s.begin(); it != s.end() && count < k; it++) {
        printf(" %d", it->index);
        count++;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    unordered_map<int, int> counts;
    set<Node> s;
    for (int i = 0; i < n; i++) {
        int index;
        scanf("%d", &index);
        if (i != 0) Output(s, index, k);
        auto it = s.find({index, counts[index]});
        if (it != s.end()) s.erase(it);
        counts[index]++;
        s.insert({index, counts[index]});
    }
    return 0;
}