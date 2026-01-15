#include <stdio.h>
#include <stdlib.h>

int encontrar_menor_nota(int *notas, int N)
{
    if (N == 1)
    {
        return notas[0];
    }

    float menor_do_resto = encontrar_menor_nota(notas + 1, N - 1);

    if (notas[0] < menor_do_resto)
        return notas[0];
    else
        return menor_do_resto;
}

int main()
{
    int N;
    scanf("%d", &N);

    float *notas;
    notas = (float *)malloc(N * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%f", &notas[i]);
    }

    float menor_nota = encontrar_menor_nota(notas, N);
    printf("%.2f\n", menor_nota);

    free(notas);

    return 0;
}