#include <stdio.h>

struct Student {
    long long id;
    int exam_num;
};

int main() {
    long long id;
    int n, m, test_num, exam_num;
    scanf("%d", &n);
    struct Student students[n + 1];
    while (n--) {
        scanf("%lld%d%d", &id, &test_num, &exam_num);
        students[test_num].id = id;
        students[test_num].exam_num = exam_num;
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &test_num);
        printf("%lld %d\n", students[test_num].id, students[test_num].exam_num);
    }
    return 0;
}