#include <stdio.h>

// TP 1 - Exerceice 9 ***
// Affichage d'un nombre en format binaire

int main() {

    int valeur_dec = 4096;
    int valeur_bin[32];     // val binaire de 32 bits
    int reste = 0;

    for (int i = 32; i>0 ; i--){
        reste = valeur_dec % 2;     // recupère 1 ou 0
        valeur_bin[i-1] = reste;        // le premier reste est le bit de poids faible
        valeur_dec = valeur_dec / 2;
    }

    for(int j = 0; j<32 ; j++){         // Affichage en binaire des 32 bits
        if (j%4 == 0)
            printf(".");
        printf("%d", valeur_bin[j]);
    }
    
    return 0;
}