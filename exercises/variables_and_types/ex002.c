#include <stdio.h>

int main() {
    int idade;
    float peso;
    char letra;

    printf("Insira sua idade: ");
    scanf("%d", &idade);

    printf("Insira seu peso: ");
    scanf("%f", &peso);

    printf("Insira uma letra: ");
    scanf(" %c", &letra);

    printf("Idade: %d\nPeso: %.2f\nLetra: %c", idade, peso, letra);

    return 0;
}