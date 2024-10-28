#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// TP3 - Exercice 4
// Recherche d'un entier dans un tableau

const int MAX = 100, MIN = 1;
const int TAILLE = 30;

int main(){

    srand(time(NULL));  // initialisation
    int tab[100];
    int *ptrTab = tab;

    // Creation du tableau d'entier avec des nombres aleatoires
    printf("Tableau: \n");
    for (int i = 0; i<TAILLE; i++){
        *(ptrTab + i) = (rand() % (MAX - MIN + 1)) + MIN;
        printf("%d ", *(ptrTab + i));
    }

    // Demande à l'utilisateur un entier
    int recherche;
    printf("\n\nEntrez l'entier que vous souhaitez rechercher dans le tableau : ");
    scanf("%d", &recherche);

    // Recherche de l'entier dans le tableau 
    bool isExist = false;
    int i = 0;
    while (isExist == false && i<TAILLE) {
        if (*(ptrTab + i) == recherche){
            isExist = true;
        }
        i++;
    }

    // Affichage reponse
    if (isExist){
        printf("\nResultat : entier present\n");
    }
    else {
        printf("\nResultat : entier absent\n");
    }
   
}