#include <stdio.h>
#include <stdio.h>

// Função que troca os valores usando ponteiros
void troca(int *a, int *b) {
    int temp;
    temp = *a;   // temp recebe o valor apontado por a
    *a = *b;     // o valor apontado por a recebe o valor apontado por b
    *b = temp;   // o valor apontado por b recebe o valor de temp
}

// Função que soma os valores usando ponteiros
int soma(int *a, int *b) {
    // Retorna a soma dos valores "desreferenciados" (conteúdo dos endereços)
    return (*a + *b);
}

int main() {
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    // Chamada da função soma (passando o endereço das variáveis com &)
    int resultado_soma = soma(&num1, &num2);
    printf("\nSoma: %d\n", resultado_soma);

    // Chamada da função troca (passando o endereço das variáveis com &)
    troca(&num1, &num2);

    // Impressão após a troca
    printf("Valores apos a troca:\n");
    printf("Numero 1: %d\n", num1);
    printf("Numero 2: %d\n", num2);

    return 0;
}