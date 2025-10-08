#include <stdio.h>

typedef struct {
    int valor;
    int frequencia;
} Numero;

void lerNumeros(Numero *vet, int *quantDif, int N) {
    int X, i, j;
    
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        
        int achou = 0;
        for (j = 0; j < *quantDif; j++) {
            if((vet + j)->valor == X) {
                (vet + j)->frequencia++;
                achou = 1;
                break;
            }
        }
        
        if (!achou) {
            (vet + *quantDif)->valor = X;
            (vet + *quantDif)->frequencia = 1;
            (*quantDif)++;
        }
    }
}

void ordenar(Numero *vet, int quantDif) {
    int i, j;
    for (i = 0; i < quantDif - 1; i++) {
        for (j = i + 1; j < quantDif; j++) {
            if ((vet + i)->valor > (vet + j)->valor) {
                Numero temp = *(vet + i);
                *(vet + i) = *(vet + j);
                *(vet + j) = temp;
            }
        }
    }
}

void imprimir(Numero *vet, int quantDif) {
    for (int i = 0; i < quantDif; i++) {
        printf("%d aparece %d vez(es)\n", (vet + i)->valor, (vet + i)->frequencia);
    }
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    Numero numeros[2000];
    int quantDif = 0;
    
    lerNumeros(numeros, &quantDif, N);
    ordenar(numeros, quantDif);
    imprimir(numeros, quantDif);
    
    return 0;
}