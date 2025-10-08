#include <stdio.h>
#include <string.h>

typedef struct {
    char palavra[51];
    int tamanho;
    int indice;
} Palavra;

void ordenarPalavras(Palavra *p, int N) {
    Palavra temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((p + i)->tamanho < (p + j)->tamanho || 
               ((p + i)->tamanho == (p + j)->tamanho &&
                (p + i)->indice > (p + j)->indice)) {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}

void imprimirPalavras(Palavra *p, int N) {
    for (int i = 0; i < N; i++) {
        printf("%s", (p + i)->palavra);
        if (i != N - 1)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d\n", &N);

    for (int f = 0; f < N; f++) {
        char linha[5000];
        fgets(linha, sizeof(linha), stdin);
        
        linha[strcspn(linha, "\n")] = '\0';
        
        Palavra palavras[5000];
        int qtdPalavras = 0;
        
        char *token = strtok(linha, " ");
        while (token != NULL) {
            strcpy((palavras + qtdPalavras)->palavra, token);
            (palavras + qtdPalavras)->tamanho = strlen(token);
            (palavras + qtdPalavras)->indice = qtdPalavras;
            qtdPalavras++;
            token = strtok(NULL, " ");
        }
        
        ordenarPalavras(palavras, qtdPalavras);
        imprimirPalavras(palavras, qtdPalavras);
    }

    return 0;
}