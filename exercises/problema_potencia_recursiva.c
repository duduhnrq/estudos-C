#include <stdio.h>

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1; // caso base
    } else {
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    int A, B;

    scanf("%d %d", &A, &B);

    printf("%d\n", potencia(A, B));

    return 0;
}