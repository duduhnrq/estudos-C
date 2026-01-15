#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char cor[20]; 
} Prateleira;

typedef struct {
    char titulo[100];
    char artista[100];
    char genero[50];
    int ano;
    int flag_ouvido;
    int codigo_prateleira;
} Vinil;

void buscar_nao_ouvidos_por_genero(const Vinil *colecao, char genero[], int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(colecao[i].genero, genero) == 0 && colecao[i].flag_ouvido == 0) {
            printf("%s\n", colecao[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título não ouvido encontrado para este gênero.");
    }
}

void buscar_titulos_por_prateleira(const Vinil *colecao, int codigo_prateleira, int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (colecao[i].codigo_prateleira == codigo_prateleira) {
            printf("%s\n", colecao[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título encontrado para esta prateleira.");
    }
}

void buscar_nao_ouvidos_por_artista_e_ano(const Vinil *colecao, char artista[], int ano_min, int ano_max, int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(colecao[i].artista, artista) == 0 && colecao[i].ano >= ano_min && colecao[i].ano <= ano_max && colecao[i].flag_ouvido == 0) {
            printf("%s\n", colecao[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título não ouvido encontrado para este artista no intervalo informado.");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Vinil *colecao;

    colecao = malloc(N * sizeof(Vinil));

    for (int i = 0; i < N; i++) {
        scanf("%s", colecao[i].titulo);
        scanf("%s", colecao[i].artista);
        scanf("%s", colecao[i].genero);
        scanf("%d", &colecao[i].ano);
        scanf("%d", &colecao[i].flag_ouvido);
        scanf("%d", &colecao[i].codigo_prateleira);
    }

    char genero_busca[50];
    scanf("%s", genero_busca);
    buscar_nao_ouvidos_por_genero(colecao, genero_busca, N);

    int codigo_prateleira_busca;
    scanf("%d", &codigo_prateleira_busca);
    buscar_titulos_por_prateleira(colecao, codigo_prateleira_busca, N);

    char artista_busca[100];
    int ano_min, ano_max;
    scanf("%s %d %d", artista_busca, &ano_min, &ano_max);
    buscar_nao_ouvidos_por_artista_e_ano(colecao, artista_busca, ano_min, ano_max, N);

    free(colecao);

    return 0;
}