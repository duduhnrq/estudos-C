#include <stdio.h>

int main() {
    int a = 3;
    float b = 4.5;
    double c = 5.678;
    float sum;

    sum = a + b + c;
    printf("The sum of a, b and c is: %.2f\n", sum);
    return 0;
}