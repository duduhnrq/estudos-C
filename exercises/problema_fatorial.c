#include <stdio.h>

int fatorial(int N) {
    if (N == 0) 
        return 1;
    else
        return N * fatorial(N - 1);
}

int main() {
    int N;
    scanf("%d", &N);

    int resultado = fatorial(N);
    printf("Resultado: %d\n", resultado);

    return 0;
}