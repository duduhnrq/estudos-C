#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    char genero[100];
    char plataforma[50];
    int ano;
    int flag;
} Jogo;

void buscar_jogos_nao_zerados_por_genero(const Jogo *jogos, char genero[], int ano_min, int ano_max, int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(jogos[i].genero, genero) == 0 && jogos[i].ano >= ano_min && jogos[i].ano <= ano_max && jogos[i].flag == 0) {
            printf("%s\n", jogos[i].nome);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum jogo encontrado!\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    Jogo *jogos;

    jogos = malloc(N * sizeof(Jogo));

    for (int i = 0; i < N; i++) {
        scanf("%s", jogos[i].nome);
        scanf("%s", jogos[i].genero);
        scanf("%s", jogos[i].plataforma);
        scanf("%d", &jogos[i].ano);
        scanf("%d", &jogos[i].flag);
    }

    char genero_busca[100];
    int ano_min, ano_max;
    scanf("%s", genero_busca);
    scanf("%d %d", &ano_min, &ano_max);

    buscar_jogos_nao_zerados_por_genero(jogos, genero_busca, ano_min, ano_max, N);

    free(jogos);

    return 0;
}