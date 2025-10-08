#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
} Horario;

int calculoDif (Horario *atual, Horario *alarme) {
    int total_atual = atual->hora * 60 + atual->minuto;
    int total_alarme = alarme->hora * 60 + alarme->minuto;
    
    int dif = total_alarme - total_atual;
    if (dif < 0)
        dif += 1440;
        
    return dif;
}

int main()
{
    int H1, M1, H2, M2, dif;
    
    while (1) {
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
        
        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
            break;
        
        Horario atual, alarme;
        
        atual.hora = H1;
        atual.minuto = M1;
        alarme.hora  = H2;
        alarme.minuto = M2;
        
        dif = calculoDif(&atual, &alarme);
        
        printf("%d\n", dif);
    }

    return 0;
}