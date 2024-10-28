#include <stdio.h>
#include <math.h>   //gcc cercle.c -o cercle -lm


//  TP1 - Exercice 2
// Calcul de l'aire et du périmètre d'un cercle en C

int main () {
    
    float rayon = 4.0;
    float aire = M_PI*rayon*rayon;
    float perimetre = 2*M_PI*rayon;

    printf("Avec un rayon de %f, l'aire est de %f et les perimetre est de %f", rayon, aire, perimetre);
}