#include <stdio.h>
#include <string.h>

typedef enum {
    ONE = 1,
    TWO,
    THREE,
} Numeros;

typedef struct {
    char one[10];
    char two[10];
    char three[10];
} Palavras;

int main() {
    int N;
    scanf("%d", &N);
    
    Palavras p;
    strcpy(p.one, "one");
    strcpy(p.two, "two");
    strcpy(p.three, "three");

    while (N--) {
        char palavra[10];
        scanf("%s", palavra);

        int len = strlen(palavra);

        if (len == 5) {
            printf("%d\n", THREE);
        } else {
            int matchOne = 0, matchTwo = 0;
            
            for (int i = 0; i < 3; i++) {
                if (palavra[i] == p.one[i]) matchOne++;
                if (palavra[i] == p.two[i]) matchTwo++;
            }
            if (matchOne >= 2) {
                printf("%d\n", ONE);
            } else if (matchTwo >= 2) {
                printf("%d\n", TWO);
            }
        }
    }
    
    return 0;
}