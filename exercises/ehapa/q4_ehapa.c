#include <stdio.h>

typedef struct {
    int comprimento;
} Lado;

int formaTriangulo(Lado *a, Lado *b, Lado *c) {
    if ((a->comprimento + b->comprimento > c->comprimento) &&
        (a->comprimento + c->comprimento > b->comprimento) &&
        (b->comprimento + c->comprimento > a->comprimento)) {
        return 1;
    }
    return 0;
}

int main() {
    Lado lados[4];
    
    for (int i = 0; i < 4; i++) {
        scanf("%d", &lados[i].comprimento);
    }
    
    int possivel = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (formaTriangulo(&lados[i], &lados[j], &lados[k])) {
                    possivel = 1;
                    break;
                }
            }
            if (possivel) break;
        }
        if (possivel) break;
    }
    
    if (possivel)
        printf("S\n");
    else
        printf("N\n");
    
    return 0;
}