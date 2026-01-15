#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int quantidade_quartos;
    int quantidade_banheiros;
    char acabamento; // 'B' ou 'P'
    int distancia;
} Casa;

void calcular_preco(Casa **casas, int N)
{
    int preco;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (casas[i][j].acabamento == 'B')
                preco = (casas[i][j].quantidade_quartos * 20) + (casas[i][j].quantidade_banheiros * 30) + (casas[i][j].distancia * 10);
            else
                preco = (casas[i][j].quantidade_quartos * 20) + (casas[i][j].quantidade_banheiros * 30) + (casas[i][j].distancia * 10) + 200;
            printf("%5d ", preco);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    Casa **casas = malloc(N * sizeof(Casa *));

    for (int i = 0; i < N; i++)
    {
        casas[i] = malloc(N * sizeof(Casa));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &casas[i][j].quantidade_quartos);
            scanf("%d", &casas[i][j].quantidade_banheiros);
            scanf(" %c", &casas[i][j].acabamento);
            if (i > j)
                casas[i][j].distancia = i - j;
            else
                casas[i][j].distancia = j - i;
        }
    }

    calcular_preco(casas, N);

    for (int i = 0; i < N; i++)
    {
        free(casas[i]);
    }
    free(casas);

    return 0;
}