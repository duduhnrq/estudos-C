#include <stdio.h>
#include <stdlib.h>

float encontrar_menor_nota(float *notas, int N) {
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

    float *notas = (float *)malloc(N * sizeof(float));
    if (notas == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%f", &notas[i]);
    }

    FILE *arquivo;
    arquivo = fopen("notas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        fprintf(arquivo, "%.2f\n", notas[i]);
    }

    fclose(arquivo);

    float menor_nota = encontrar_menor_nota(notas, N);
    printf("%.2f\n", menor_nota);

    arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao reabrir arquivo!\n");
        return 1;
    }

    float nota_lida;
    while (fscanf(arquivo, "%f", &nota_lida) != EOF) {
        printf("%.2f ", nota_lida);
    }
    printf("\n");

    fclose(arquivo);

    free(notas);

    return 0;
}