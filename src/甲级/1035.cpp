#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Account {
    string name;
    string password;
};

map<char, char> transfer { {'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'} };

int main() {
    int n;
    cin >> n;
    vector<Account> accounts(n), modified;
    for (int i = 0; i < n; i++)
        cin >> accounts[i].name >> accounts[i].password;
    for (auto account : accounts) {
        bool flag = false;
        for (auto &c : account.password) {
            if (transfer.count(c)) {
                flag = true;
                c = transfer[c];
            }
        }
        if (flag) modified.push_back(account);
    }
    if (modified.empty()) {
        if (accounts.size() == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << n << " accounts and no account is modified" << endl;
    } else {
        cout << modified.size() << endl;
        for (auto account : modified)
            cout << account.name << ' ' << account.password << endl;
    }
    return 0;
}