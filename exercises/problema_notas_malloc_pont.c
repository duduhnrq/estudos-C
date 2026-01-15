#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float nota1;
    float nota2;
    float nota3;
} Notas;

typedef struct
{
    char nome[100];
    Notas nota;
    float media_notas;
} Aluno;

int main()
{
    int N;
    scanf("%d", &N);

    Aluno *alunos = malloc(N * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%s", alunos[i].nome);
        scanf("%f", &alunos[i].nota.nota1);
        scanf("%f", &alunos[i].nota.nota2);
        scanf("%f", &alunos[i].nota.nota3);
        alunos[i].media_notas = (alunos[i].nota.nota1 + alunos[i].nota.nota2 + alunos[i].nota.nota3) / 3.0;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s\n", alunos[i].nome);
        printf("%.2f\n", alunos[i].media_notas);
    }

    free(alunos);

    return 0;
}