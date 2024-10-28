#include <stdio.h>

// TP2 - Exercice 3
// Génération de la Suite de Fibonacci en C

int main(){
    int n = 7;          // calcul de un
    int un[20] = {0,1};     // défini avec u0 = 0 et u1 = 1
    int ui;
    printf("La suite de Fibonacci de %d est %d, %d ", n, un[0], un[1]);

    for (int i = 2; i<n; i++){
        ui = un[i-1] + un[i-2];
        un[i]=ui;
        printf(",%d ", ui );
    }

}