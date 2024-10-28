#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TP3 - Exercice 3
// Tri croissant d'un tableau

const int MAX = 100, MIN = 1;
const int TAILLE = 100;

// méthode de tri à bulle
void triTab(int taille, int *ptrTab) {
    int tmp;
    for (int i = taille; i >= 1; i--){
        for(int j = 0; j <= i-1; j++){
            if (*(ptrTab + j) > *(ptrTab + j + 1)){     // si la 2e valeur est supérieur alors échnage de val
                tmp = *(ptrTab + j + 1);
                *(ptrTab + j + 1) = *(ptrTab + j);
                *(ptrTab + j) = tmp;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int tab[100];
    int *ptrTab = tab;


    // Creation du tableau d'entier avec des nombres aleatoires
    printf("Tableau non trié : \n");
    for (int i = 0; i<TAILLE; i++){
        *(ptrTab + i) = (rand() % (MAX - MIN + 1)) + MIN;
        printf("%d ", *(ptrTab + i));
    }

    // Tri du tableau 
    triTab(TAILLE, ptrTab);
    
    // Affichage tableau trié
    printf("\nTableau trié par ordre croissant : \n");
    for (int i = 0; i< TAILLE; i++){
        printf("%d ", *(ptrTab + i));
    }
   
}