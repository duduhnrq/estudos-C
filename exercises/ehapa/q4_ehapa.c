#include <stdio.h>
#include <string.h>

struct Participante {
    char idioma[20];
}typedef Participante;

int main() {
    int N, K, i, j;
    
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        scanf("%d", &K);
        
        Participante p[K];
        
        for (j = 0; j < K; j++) {
            scanf("%s", p[j].idioma);
        }
        
        char idioma_base[20];
        strcpy(idioma_base, p[0].idioma);
        
        int todos_iguais = 1;
        
        for (j = 1; j < K; j++) {
            if (strcmp(p[j].idioma, idioma_base) != 0) {
                todos_iguais = 0;
                break;
            }
        }
        
        if (todos_iguais) {
            printf("%s\n", idioma_base);
        } else {
            printf("ingles\n");
        }
    }
    
    return 0;
}