#include <stdio.h>

// TP1 -Exercice 6
// Affichage d'un triangle rectangle avec des boucles

int main(){

    int compteur = 7;

    // methode for
    printf("Avec la methode for \n");
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <=i; j++){
            if (j == 1 || j ==i || i == compteur)   
                printf("*");    // extremite du triangle
            else    
                printf("#");    // interieur du triangle
        }
        printf("\n");
    }

    // methode while
    int i = 1;
    int j = 1;
    printf("\n Avec la methode while :\n");
    
    while(i <= compteur){
        j = 1;
        while (j <=i){
            if (j == 1 || j ==i || i == compteur)
                printf("*");
            else 
                printf("#");
            j++;
        }
        printf("\n");
        i++; 
    }
    

    return 0;
}