#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
    char plano[50];
    int flag;
} Aluno;

void buscar_alunos_ativos_por_plano(const Aluno *alunos, char plano[], int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(alunos[i].plano, plano) == 0 && alunos[i].flag == 1) {
            printf("%s\n", alunos[i].nome);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum aluno ativo neste plano.");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Aluno *alunos;

    alunos = malloc(N * sizeof(Aluno));

    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i].nome);
        scanf("%d", &alunos[i].idade);
        scanf("%s", alunos[i].plano);
        scanf("%d", &alunos[i].flag);
    }

    char plano_busca[50];
    scanf("%s", plano_busca);
    buscar_alunos_ativos_por_plano(alunos, plano_busca, N);

    free(alunos);

    return 0;
}