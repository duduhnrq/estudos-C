#include <stdio.h>

void guessNumber(int guess) {
    if (guess < 555) {
        printf("Your guess %d is too low.\n", guess);
    } else if (guess > 555) {
        printf("Your guess %d is too high.\n", guess);
    } else {
        printf("Congratulations! Your guess %d is correct.\n", guess);
    }
}

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}