#include <stdio.h>

// TP2 - Exercice 1
// Calcul de la Puissance a^b

int main(){
    int a = 3;
    int b = 5;
    int resultat = a;

    for (int i = 1; i<b ; i++){
        resultat *= a;
    }

    printf("Le resultat de %d^%d est %d :", a, b, resultat);
}