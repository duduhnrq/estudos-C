#include <stdio.h>

typedef struct {
    int tamanho;
    int quadrados;
} Grade;

int main() {
    int N;
    
    while (scanf("%d", &N), N != 0) {
        Grade g;
        g.tamanho = N;
        g.quadrados = 0;
        
        for (int i = 1; i <= N; i++) {
            g.quadrados += i * i;
        }
        
        printf("%d\n", g.quadrados);   
    }

    return 0;
}