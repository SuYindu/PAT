#include <iostream>
using namespace std;

int main() {
    char num2char[3] = {'W', 'T', 'L'};
    double total_odd = 1.0;
    for (int i = 0; i < 3; i++) {
        int best_result = -1;
        double max_odd = 0.0;
        for (int j = 0; j < 3; j++) {
            double odd;
            cin >> odd;
            if (odd > max_odd) {
                max_odd = odd;
                best_result = j;
            }
        }
        total_odd *= max_odd;
        printf("%c ", num2char[best_result]);
    }
    printf("%.2f\n", (total_odd * 0.65 - 1) * 2);
    return 0;
}