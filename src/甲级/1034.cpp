#include <iostream>
#include <map>
using namespace std;

struct Gang { int num, val, max; };

const int MAX_N = 2005;
bool marked[MAX_N];
int weights[MAX_N];
int graph[MAX_N][MAX_N];
map<string, Gang> ans;

map<string, int> name2id;
map<int, string> id2name;
int id(string name) {
    if (!name2id.count(name)) name2id[name] = name2id.size();
    id2name[name2id[name]] = name;
    return name2id[name];
}

void dfs(int v, Gang &gang) {
    marked[v] = true;
    gang.num++;
    gang.val += weights[v];
    gang.max = weights[v] > weights[gang.max] ? v : gang.max;
    
    for (int w = 0; w < name2id.size(); w++)
        if (!marked[w] && graph[v][w]) dfs(w, gang);
}

void dfs(int k) {
    for (int v = 0; v < name2id.size(); v++) {
        if (marked[v]) continue;
        Gang gang{0, 0, v};
        dfs(v, gang);
        if (gang.num > 2 && gang.val > 2 * k)
            ans[id2name[gang.max]] = gang;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int weight;
        string name1, name2;
        cin >> name1 >> name2 >> weight;
        int v = id(name1), w = id(name2);
        weights[v] += weight, weights[w] += weight;
        graph[v][w] = graph[w][v] = weight;
    }
    dfs(k);

    cout << ans.size() << endl;
    for (auto pair : ans)
        cout << pair.first << " " << pair.second.num << endl;
    return 0;
}