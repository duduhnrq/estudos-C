#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Digite o número de elementos: ");
    scanf("%d", &N);

    int *vetor = malloc(N * sizeof(int));

    printf("Digite os %d números: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Os números digitados são: ");
    for (int i = 0; i < N; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}