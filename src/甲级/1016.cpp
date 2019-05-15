#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Date {
    string str;
    int month, day, hour, minute;

    friend istream & operator>>(istream &in, Date &date) {
        cin >> date.str;
        date.month  = stoi(date.str.substr(0, 2));
        date.day    = stoi(date.str.substr(3, 2));
        date.hour   = stoi(date.str.substr(6, 2));
        date.minute = stoi(date.str.substr(9, 2));
        return in;
    }
};

struct Record {
    string name;
    Date date;
    string state;
};

struct BillRecord {
    string begin, end;
    int duration;
    double charge;

    BillRecord(string begin, string end, int duration, double charge) : 
    begin(begin), end(end), duration(duration), charge(charge) {}
};

int main() {
    int n, tolls[24];
    for (int i = 0; i < 24; i++)
        cin >> tolls[i];
    cin >> n;
    Record records[n];
    for (int i = 0; i < n; i++)
        cin >> records[i].name >> records[i].date >> records[i].state;

    sort(records, records + n, [](Record a, Record b) {
        return a.name != b.name ? a.name < b.name : a.date.str < b.date.str;
    }); // 按姓名和时间排序，以筛去无效记录
    map<string, vector<BillRecord>> bills;
    for (int i = 0; i < n - 1; i++) {
        if (records[i].name != records[i+1].name || records[i].state != "on-line" || records[i+1].state != "off-line") continue;
        Date begin = records[i].date, end = records[i+1].date;
        int duration = 0, charge = 0;
        while (begin.day != end.day || begin.hour != end.hour || begin.minute != end.minute) {
            duration++;
            charge += tolls[begin.hour];
            if (++begin.minute == 60) {
                begin.minute = 0;
                begin.hour++;
            }
            if (begin.hour == 24) {
                begin.hour = 0;
                begin.day++;
            }
        }
        // 注意总花费以美元为单位，需要换算
        bills[records[i].name].push_back(BillRecord(records[i].date.str.substr(3), records[i+1].date.str.substr(3), duration, (double)charge / 100));
    }

    int month = records[0].date.month;
    for (auto bill : bills) {
        printf("%s %02d\n", bill.first.c_str(), month);
        double total = 0.0;
        for (auto record : bill.second) {
            printf("%s %s %d $%.2f\n", record.begin.c_str(), record.end.c_str(), record.duration, record.charge);
            total += record.charge;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}