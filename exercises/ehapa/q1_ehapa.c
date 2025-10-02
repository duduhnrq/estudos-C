#include <stdio.h>
#include <string.h>

typedef enum {
    VERTEBRADO,
    INVERTEBRADO
} Tipo;

typedef enum {
    AVE,
    MAMIFERO,
    INSETO,
    ANELIDEO
} Classe;

typedef enum {
    CARNIVORO,
    ONIVORO,
    HERBIVORO,
    HEMATOFAGO
} Dieta;

typedef struct {
    Tipo tipo;
    Classe classe;
    Dieta dieta;
} Animal;

int main() {
    char s1[20], s2[20], s3[20];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    
    Animal a;
    
    if (strcmp(s1, "vertebrado") == 0)
        a.tipo = VERTEBRADO;
    else
        a.tipo = INVERTEBRADO;
    
    if (strcmp(s2, "ave") == 0)
        a.classe = AVE;
    else if (strcmp(s2, "mamifero") == 0)
        a.classe = MAMIFERO;
    else if (strcmp(s2, "inseto") == 0)
        a.classe = INSETO;
    else
        a.classe = ANELIDEO;
        
    if (strcmp(s3, "carnivoro") == 0)
        a.dieta = CARNIVORO;
    else if (strcmp(s3, "onivoro") == 0)
        a.dieta = ONIVORO;
    else if (strcmp(s3, "herbivoro") == 0)
        a.dieta = HERBIVORO;
    else
        a.dieta = HEMATOFAGO;
        
    if (a.tipo == VERTEBRADO && a.classe == AVE && a.dieta == CARNIVORO)
        printf("aguia\n");
    else if (a.tipo == VERTEBRADO && a.classe == AVE && a.dieta == ONIVORO)
        printf("pomba\n");
    else if (a.tipo == VERTEBRADO && a.classe == MAMIFERO && a.dieta == ONIVORO)
        printf("homem\n");
    else if (a.tipo == VERTEBRADO && a.classe == MAMIFERO && a.dieta == HERBIVORO)
        printf("vaca\n");
    else if (a.tipo == INVERTEBRADO && a.classe == INSETO && a.dieta == HEMATOFAGO)
        printf("pulga\n");
    else if (a.tipo == INVERTEBRADO && a.classe == INSETO && a.dieta == HERBIVORO)
        printf("lagarta\n");
    else if (a.tipo == INVERTEBRADO && a.classe == ANELIDEO && a.dieta == HEMATOFAGO)
        printf("sanguessuga\n");
    else if (a.tipo == INVERTEBRADO && a.classe == ANELIDEO && a.dieta == ONIVORO)
        printf("minhoca\n");
    
    return 0;
}