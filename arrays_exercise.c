#include <stdio.h>

int main() {
    int grades[2][5];
    float average;
    int i, j;

    grades[0][0] = 85;
    grades[0][1] = 90;
    grades[0][2] = 78;
    grades[0][3] = 88;
    grades[0][4] = 92;

    grades[1][0] = 80;
    grades[1][1] = 75;
    grades[1][2] = 85;
    grades[1][3] = 90;
    grades[1][4] = 95;

    for (i = 0; i < 2; i++) {
        average = 0;
        for (j = 0; j < 5; j++) {
            average += grades[i][j];
        }

        average /= 5;
        printf("The average marks obtained in subject %d is: %.2f\n", i, average);
    }

    return 0;
}