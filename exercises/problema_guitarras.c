#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int quant_captadores;
    int quant_trastes;
    char tipo_madeira; // 'A' ou 'N'
    int distancia;
} Guitarra;

void calcular_preco_guitarra(Guitarra **matriz, int N)
{
    int preco;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matriz[i][j].tipo_madeira == 'A')
                preco = (matriz[i][j].quant_captadores * 80) + (matriz[i][j].quant_trastes * 15) + 120 + (matriz[i][j].distancia * 25);
            else
                preco = (matriz[i][j].quant_captadores * 80) + (matriz[i][j].quant_trastes * 15) + 300 + (matriz[i][j].distancia * 25);
            printf("%4d ", preco);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    Guitarra **matriz;
    matriz = malloc(N * sizeof(Guitarra*));

    for (int i = 0; i < N; i++)
    {
        matriz[i] = malloc(N * sizeof(Guitarra));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matriz[i][j].quant_captadores);
            scanf("%d", &matriz[i][j].quant_trastes);
            scanf(" %c", &matriz[i][j].tipo_madeira);
            if (i > j)
                matriz[i][j].distancia = i - j;
            else
                matriz[i][j].distancia = j - i;
        }
    }

    calcular_preco_guitarra(matriz, N);

    for (int i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}