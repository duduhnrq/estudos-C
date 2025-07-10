#include <stdio.h>

int main() {
    // Using a for loop to print numbers from 1 to 10
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    // Using a for loop to calculate the sum of numbers from 1 to 10
    /* int sum = 0;
    for (int j = 1; j <= 10; j++) {
        sum += j;
    }
    printf("Sum of numbers from 1 to 10 is: %d\n", sum); */

    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0;
    int i;

    for (i = 0; i < 10; i++) {
        sum += array[i];
    }

    /* sum now contains a[0] + a[1] + ... + a[9] */
    printf("Sum of the array is %d\n", sum);

    return 0;
}