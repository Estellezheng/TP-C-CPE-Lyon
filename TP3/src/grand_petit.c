#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TP3 - Exercice 2
// Trouver le numéro le plus grand et le plus petit dans un tableau

const int MAX = 1000, MIN = 1;

int main(){
    srand(time(NULL));  // initialisation
    int tab[100];
    int *ptrTab = tab;
    int min = 1000;
    int max = 0;

    for (int i = 0; i<100; i++){
        *(ptrTab + i) = (rand() % (MAX - MIN + 1)) + MIN;
        if (tab[i] < min) {
            min = *(ptrTab + i);
        }
        if (tab[i] > max) {
            max = *(ptrTab + i);
        }
    }

    // Affichage résultat
    printf("Le numero le plus grand est : %d \n", max);
    printf("Le numero le plus petit est : %d \n", min);
}