#include <iostream>
using namespace std;

int main() {
    char num2char[] = {'W', 'T', 'L'};
    double total_odd = 1.0;
    for (int i = 0; i < 3; i++) {
        int index = -1;
        double odd, max_odd = 0.0;
        for (int j = 0; j < 3; j++) {
            cin >> odd;
            if (odd > max_odd) {
                max_odd = odd;
                index = j;
            }
        }
        total_odd *= max_odd;
        printf("%c ", num2char[index]);
    }
    printf("%.2f\n", (total_odd * 0.65 - 1) * 2);
    return 0;
}