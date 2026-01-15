#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VINIS 500

typedef struct {
    int codigo;
    char cor[20];
} Prateleira;

typedef struct {
    char titulo[100];
    char artista[100];
    char genero[50];
    int ano;
    int flag; // 1 = sim, 0 = não
    int codigo_prateleira;
} Vinil;

void buscar_nao_ouvidos_por_genero(const Vinil v[], int n, const char gen[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].genero, gen) == 0 && v[i].flag == 0) {
            printf("%s\n", v[i].titulo);
        }
    }
}

int main() {
    Vinil v[MAX_VINIS];

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", v[i].titulo);
        scanf("%s", v[i].artista);
        scanf("%s", v[i].genero);
        scanf("%d", v[i].ano);
        scanf("%d", v[i].flag);
        scanf("%d", v[i].codigo_prateleira);
    }

    char gen[50];
    scanf("%s", gen);
    buscar_nao_ouvidos_por_genero(v, N, gen);   

    return 0;
}