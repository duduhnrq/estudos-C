#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int ano;
    int flag;
} Livro;

void buscar_nao_lidos_por_autor(const Livro *acervo, char autor[], int N) {
    int encontrado = 0;

    for (int i = 0; i < N; i++) {
        if (strcmp(acervo[i].autor, autor) == 0 && acervo[i].flag == 0) {
            printf("%s\n", acervo[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro não lido encontrado.\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Livro *acervo;

    acervo = malloc(N * sizeof(Livro));

    for (int i = 0; i < N; i++) {
        scanf("%s", acervo[i].titulo);
        scanf("%s", acervo[i].autor);
        scanf("%d", &acervo[i].ano);
        scanf("%d", &acervo[i].flag);
    }

    char autor_busca[100];
    scanf("%s", autor_busca);
    buscar_nao_lidos_por_autor(acervo, autor_busca, N);

    free(acervo);

    return 0;
}