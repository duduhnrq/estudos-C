#include <stdio.h>;
#include <string.h>;

typedef struct {
    int codigo_vinil;
    int numero_prateleira;
    char nome_prateleira[100];
} Prateleira;

typedef struct {
    int codigo_vinil;
    char titulo[100];
    int quantidade_musicas;
    int flag_ouvido;
    char nome_musica[100];
    int ano;
} Vinil;

void verificar_vinis_v1(Vinil vinis[], Prateleira prateleiras[], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vinis[i].flag_ouvido == 1 && vinis[i].codigo_vinil == prateleiras[j].codigo_vinil && vinis[i].ano > 2010 && vinis[i].ano < 2020) {
                printf("%s\n", vinis[i].titulo);
            }
        }
    }
}

void verificar_vinis_v2(Vinil vinis[], int N) {
    int contador = 0;

    for (int i = 0; i < N; i++) {
        if (vinis[i].flag_ouvido == 1 && vinis[i].ano >= 1990 && vinis[i].ano <= 2010) {
            printf("%d\n", vinis[i].codigo_vinil);
            printf("%s\n", vinis[i].titulo);
            printf("%d\n", vinis[i].ano);
            contador++;
        }
    }

    printf("Vinis encontrados: %d\n", contador);
}

void verificar_prateleira(Vinil vinis[], Prateleira prateleiras[], int numero_prateleira, int N, int M) {
    int contador = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (prateleiras[j].numero_prateleira == numero_prateleira && prateleiras[j].codigo_vinil == vinis[i].codigo_vinil) {
                if (vinis[i].flag_ouvido == 0) {
                    vinis[i].flag_ouvido = 1;
                    contador++;
                }                
            }
        }
    }

    printf("Vinis atualizados: %d\n", contador);
}

int main() {
    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    Vinil vinis[N];
    Prateleira prateleiras[M];

    for (int i = 0; i < N; i++) {
        scanf("%d", &vinis[i].codigo_vinil);
        scanf("%s", vinis[i].titulo);
        scanf("%d", &vinis[i].quantidade_musicas);
        scanf("%d", &vinis[i].flag_ouvido);
        scanf("%s", vinis[i].nome_musica);
        scanf("%d", &vinis[i].ano);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &prateleiras[i].codigo_vinil);
        scanf("%d", &prateleiras[i].numero_prateleira);
        scanf("%s", prateleiras[i].nome_prateleira);
    }

    verificar_vinis_v1(vinis, prateleiras, N, M);
    verificar_vinis_v2(vinis, N);

    int numero_prateleira_busca;
    scanf("%d", &numero_prateleira_busca);
    verificar_prateleira(vinis, prateleiras, numero_prateleira_busca, N, M);

    return 0;
}