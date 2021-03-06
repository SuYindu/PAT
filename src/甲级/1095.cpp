#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Record {
    string plate, time, state;
    bool valid = false;
};

int get_duration(string in_time, string out_time) {
    int hour   = stoi(out_time.substr(0, 2)) - stoi(in_time.substr(0, 2));
    int minite = stoi(out_time.substr(3, 2)) - stoi(in_time.substr(3, 2));
    int second = stoi(out_time.substr(6, 2)) - stoi(in_time.substr(6, 2));
    return hour * 3600 + minite * 60 + second;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Record> records(n);
    for (int i = 0; i < n; i++)
        cin >> records[i].plate >> records[i].time >> records[i].state;
    // 按车牌号和时间排序，以过滤无效记录
    sort(records.begin(), records.end(), [](Record r1, Record r2) {
        return r1.plate != r2.plate ? r1.plate < r2.plate : r1.time < r2.time;
    });
    for (int i = 0; i < n - 1; i++)
        if (records[i].plate == records[i+1].plate && records[i].state == "in" && records[i+1].state == "out")
            records[i].valid = records[i+1].valid = true;
    sort(records.begin(), records.end(), [](Record r1, Record r2) {
        return r1.time < r2.time;
    });
    map<string, int> count;
    map<string, int> durations;
    map<string, string> in_time;
    for (auto record : records) {
        if (!record.valid) continue;
        if (record.state == "in") {
            in_time[record.plate] = record.time;
            if (count.empty())
                count[record.time] = 1;
            else
                count[record.time] = count.rbegin()->second + 1; // 车辆增加
        } else {
            durations[record.plate] += get_duration(in_time[record.plate], record.time);
            count[record.time] = count.rbegin()->second - 1; // 车辆减少
        }
    }
    auto cur  = count.begin();
    auto prev = count.begin();
    while (k--) {
        string time;
        cin >> time;
        while (cur != count.end() && cur->first <= time)
            prev = cur++;
        cout << prev->second << endl;
    }
    int max_time = 0;
    for (auto pair : durations)
        max_time = max(pair.second, max_time);
    for (auto pair : durations)
        if (pair.second == max_time)
            cout << pair.first << " ";
    printf("%02d:%02d:%02d\n", max_time / 3600, (max_time % 3600) / 60, max_time % 60);
    return 0;
}