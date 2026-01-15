#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char placa[10];
    char modelo[50];
    int ano;
    int flag;
    int num_vaga;
} Veiculo;

int main() {
    int N;
    scanf("%d", &N);
    
    Veiculo *veiculos;

    veiculos = malloc(N * sizeof(Veiculo));

    for (int i = 0; i < N; i ++) {
        scanf("%s", veiculos[i].placa);
        scanf("%s", veiculos[i].modelo);
        scanf("%d", &veiculos[i].ano);
        scanf("%d", &veiculos[i].flag);
        scanf("%d", &veiculos[i].num_vaga);
    }

    int numero_vaga;
    scanf("%d", &numero_vaga);

    int encontrado = 0;
    for (int i = 0; i < N; i ++) {
        if (veiculos[i].num_vaga == numero_vaga) {
            printf("%s\n", veiculos[i].modelo);
            encontrado = 1;
        }
    }
    if(!encontrado) {
        printf("Nenhum veículo estacionado nessa vaga.");
    }

    free(veiculos);

    return 0;
}