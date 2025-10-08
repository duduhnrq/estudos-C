#include <stdio.h>

#define MAX 500

typedef struct {
    int velocidade;
} Lesma;

int velocidadeMaxima(Lesma *lesmas, int qtd) {
    int max = lesmas[0].velocidade;
    for (int i = 1; i < qtd; i++) {
        if ((lesmas + i)->velocidade > max) {
            max = (lesmas + i)->velocidade;
        }
    }
    return max;
}

int classificarCorrida(int velMax) {
    if (velMax < 10)
        return 1;
    else if (velMax < 20)
        return 2;
    else
        return 3;
}

int main() {
    int L;
    Lesma lesmas[MAX];

    while (scanf("%d", &L) != EOF) {
        for (int i = 0; i < L; i++) {
            scanf("%d", &(lesmas[i].velocidade));
        }

        int max = velocidadeMaxima(lesmas, L);
        int nivel = classificarCorrida(max);

        printf("%d\n", nivel);
    }

    return 0;
}
