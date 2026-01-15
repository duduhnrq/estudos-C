#include <stdio.h>
#include <string.h>

#define MAX_VINIS 500

// --- Definição das Structs ---

typedef struct {
    int codigo;
    char cor[20];
} Prateleira;

typedef struct {
    char titulo[100];
    char artista[100];
    char genero[50];
    int ano;
    int flag_ouvido; // 1 = sim, 0 = não
    int codigo_prateleira;
} Vinil;

// --- Funções de Processamento do Problema ---

// 1. Imprime títulos não ouvidos de um gênero
void buscar_nao_ouvidos_por_genero(const Vinil colecao[], int n, const char genero_alvo[]) {
    int encontrado = 0;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(colecao[i].genero, genero_alvo) == 0 && colecao[i].flag_ouvido == 0) {
            printf("%s\n", colecao[i].titulo); 
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título não ouvido encontrado para este gênero.\n");
    }
}

// 2. Imprime títulos por código de prateleira
void buscar_titulos_por_prateleira(const Vinil colecao[], int n, int codigo_alvo) {
    int encontrado = 0;
    
    for (int i = 0; i < n; i++) {
        if (colecao[i].codigo_prateleira == codigo_alvo) {
            printf("%s\n", colecao[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título encontrado para esta prateleira.\n");
    }
}

// 3. Imprime títulos não ouvidos de um artista em um intervalo de anos
void buscar_nao_ouvidos_por_artista_e_ano(const Vinil colecao[], int n, const char artista_alvo[], int ano_min, int ano_max) {
    int encontrado = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(colecao[i].artista, artista_alvo) == 0 && 
            colecao[i].flag_ouvido == 0 && 
            colecao[i].ano >= ano_min && 
            colecao[i].ano <= ano_max) 
        {
            printf("%s\n", colecao[i].titulo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum título não ouvido encontrado para este artista no intervalo informado.\n");
    }
}

// --- Função Principal Minimalista ---

int main() {
    Vinil colecao[MAX_VINIS]; 
    int N; 

    // 1. Leitura de N (Número de Vinis)
    scanf("%d", &N);

    // 2. Leitura dos N vinis (Usando scanf("%s") para todas as strings)
    for (int i = 0; i < N; i++) {
        // Leitura na ordem: Título, Artista, Gênero, Ano, Flag, Código_Prateleira
        
        // ATENÇÃO: Se o título tiver espaços, apenas a primeira palavra será lida!
        scanf("%s", colecao[i].titulo);
        scanf("%s", colecao[i].artista);
        scanf("%s", colecao[i].genero);

        // Para inteiros, scanf funciona bem:
        scanf("%d", &colecao[i].ano);
        scanf("%d", &colecao[i].flag_ouvido);
        scanf("%d", &colecao[i].codigo_prateleira);
    }

    // --- Processamento das 3 Consultas ---
    
    // Consulta 1: Gênero e Não Ouvidos
    char genero_busca[50];
    scanf("%s", genero_busca);
    buscar_nao_ouvidos_por_genero(colecao, N, genero_busca);

    // Consulta 2: Código de Prateleira
    int codigo_prateleira_busca;
    scanf("%d", &codigo_prateleira_busca);
    buscar_titulos_por_prateleira(colecao, N, codigo_prateleira_busca);

    // Consulta 3: Artista, Intervalo de Anos e Não Ouvidos
    char artista_busca[100];
    int ano_min, ano_max;
    
    scanf("%s", artista_busca);
    scanf("%d", &ano_min);
    scanf("%d", &ano_max);

    buscar_nao_ouvidos_por_artista_e_ano(colecao, N, artista_busca, ano_min, ano_max);

    return 0;
}