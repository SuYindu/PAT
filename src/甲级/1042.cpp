#include <iostream>
#include <vector>
using namespace std;

const int NUM_CARDS = 54;
const int NUM_SUITS = 13;
const string suits[] = {"S", "H", "C", "D", "J"};

int main() {
    int k, order[NUM_CARDS];
    cin >> k;
    for (int i = 0; i < NUM_CARDS; i++)
        cin >> order[i];
    vector<string> deck(NUM_CARDS);
    for (int i = 0; i < NUM_CARDS; i++)
        deck[i] = suits[i / NUM_SUITS] + to_string(i % NUM_SUITS + 1);

    while (k--) {
        vector<string> temp(deck);
        for (int i = 0; i < NUM_CARDS; i++)
            deck[order[i] - 1] = temp[i];
    }

    for (int i = 0; i < NUM_CARDS; i++)
        cout << deck[i] << (i < NUM_CARDS - 1 ? ' ' : '\n');

    return 0;
}