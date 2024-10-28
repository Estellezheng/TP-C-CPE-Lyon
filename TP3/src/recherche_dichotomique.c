#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TP3 - Exercice 5
// Recherche dichotomique dans un tableau trié

const int MAX = 200, MIN = 1;
const int TAILLE = 100;

int dichotomie(int taille, int *ptrTab, int recherche){
    int gauche = 0;
    int droite = taille -1;
    int milieu;
    while (gauche <= droite) {
        milieu = (gauche + droite) / 2;
        if (*(ptrTab + milieu) == recherche){
            return 1;
        }
        else if (*(ptrTab + milieu) < recherche){
            gauche = milieu + 1;
        }
        else{
            droite = milieu - 1;
        }
    }
    return 0;
}


int main(){
    srand(time(NULL));
    int tab[TAILLE];
    int *ptrTab = tab;

    // creation tableau aletoire
    for (int i = 0; i<TAILLE; i++){
        *(ptrTab + i) = (rand() % (MAX - MIN + 1)) + MIN;
    }

    // tri du tableau
    int tmp;
    for (int i = TAILLE; i >= 1; i--){
        for(int j = 0; j <= i-1; j++){
            if (*(ptrTab + j) > *(ptrTab + j + 1)){
                tmp = *(ptrTab + j + 1);
                *(ptrTab + j + 1) = *(ptrTab + j);
                *(ptrTab + j) = tmp;
            }
        }
    }

    // Affichage tableau
    for (int i = 0; i<TAILLE; i++){
        printf("%d ", *(ptrTab + i));
    }

    // Demande à l'utilisateur un entier
    int recherche;
    printf("\n\nEntrez l'entier que vous souhaitez rechercher dans le tableau : ");
    scanf("%d", &recherche);


    // Recherche dichotomique, de l'entier dans le tableau et Affichage reponse
    if (dichotomie(TAILLE, ptrTab, recherche)){
        printf("\nResultat : entier present\n");
    }
    else {
        printf("\nResultat : entier absent\n");
    }
}

