#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TP2 - Exercice 9
// Manipulation de Tableaux avec des Pointeurs


const int MAX = 100, MIN = 1;
const int TAILLE = 10;

int main(){
    srand(time(NULL));

    int tabEntier[TAILLE];
    int *ptrTabEntier = tabEntier;
    
    float tabFloat[TAILLE];
    float *ptrTabFloat = tabFloat;

    // Génération d'un tableau alétoire avec des pointeurs
    printf("Tableau d'entiers\n");
    for (int i = 0; i<TAILLE; i++){
        *(ptrTabEntier + i) = (rand() % (MAX - MIN + 1)) + MIN;
        printf("%d ", *(ptrTabEntier + i));
    }

    // Tableau multiplié par 3
    printf("\nTableau d'entiers multiplié par 3\n");
    for (int i = 0; i<TAILLE; i++){
        if (i%2 == 0){
            *(ptrTabEntier + i) *= 3;
        }
        printf("%d ", *(ptrTabEntier + i));
    }


    printf("\n\nTableau de floats\n");
    for (int i = 0; i<TAILLE; i++){
        *(ptrTabFloat + i) = ((float)rand() / RAND_MAX) * (MAX - MIN) + MIN;
        printf("%.1f ", *(ptrTabFloat + i));
    }

    printf("\nTableau de float multiplié par 3\n");
    for (int i = 0; i<TAILLE; i++){
        if (i%2 == 0){
            *(ptrTabFloat + i) *= 3;
        }
        printf("%.1f ", *(ptrTabFloat + i));
    }
    
}