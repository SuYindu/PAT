#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    string first_id, first_time = "23:59:59";
    string last_id, last_time = "00:00:00";
    while (m--) {
        string id, in, out;
        cin >> id >> in >> out;
        if (in < first_time) {
            first_id = id;
            first_time = in;
        }
        if (out > last_time) {
            last_id = id;
            last_time = out;
        }
    }
    cout << first_id << " " << last_id << endl;
    return 0;
}