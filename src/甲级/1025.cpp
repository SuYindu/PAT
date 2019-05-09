#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Testee {
    string id;
    int score;
    int location;
    int local_rank;
    int final_rank;
};

bool compare(Testee a, Testee b) {
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    vector<Testee> local_testees[n];
    vector<Testee> global_testees;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        local_testees[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> local_testees[i][j].id >> local_testees[i][j].score;
            local_testees[i][j].location = i + 1;
        }
        
        sort(local_testees[i].begin(), local_testees[i].end(), compare);
        local_testees[i].front().local_rank = 1;
        for (int j = 1; j < k; j++)
            local_testees[i][j].local_rank = 
            local_testees[i][j].score < local_testees[i][j-1].score ? 
            j + 1 : local_testees[i][j-1].local_rank;
            
        for (auto testee : local_testees[i])
            global_testees.push_back(testee);
    }

    sort(global_testees.begin(), global_testees.end(), compare);
    global_testees.front().final_rank = 1;
    for (int i = 1; i < global_testees.size(); i++)
        global_testees[i].final_rank = 
        global_testees[i].score < global_testees[i-1].score ? 
        i + 1 : global_testees[i-1].final_rank; 

    printf("%lu\n", global_testees.size());
    for (auto testee : global_testees)
        printf("%s %d %d %d\n", testee.id.c_str(), testee.final_rank, testee.location, testee.local_rank);
    return 0;
}