#include <stdio.h>

int main() {
    int grades[2][5] = {
        {85, 90, 78, 88, 92}, // Grades for subject 0
        {80, 75, 85, 90, 95}  // Grades for subject 1
    };
    char subjects[2][20] = {
        "Mathematics",
        "Science"
    };
    float average;
    int i, j;

    for (i = 0; i < 2; i++) {
        average = 0;
        for (j = 0; j < 5; j++) {
            average += grades[i][j];
        }

        average /= 5;
        printf("The average marks obtained in subject %d is: %.2f\n", subjects[i], average);
    }

    return 0;
}