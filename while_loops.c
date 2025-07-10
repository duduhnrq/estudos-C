#include <stdio.h>

int main() {
    int n = 0;
    while (n < 10) {
        n++;
        printf("%d\n", n);
    }

    int m = 0;
    while (1) {
        m++;
        printf("%d\n", m);
        if (m == 10) {
            break;
        }
    }
}