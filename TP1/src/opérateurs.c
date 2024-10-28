#include <stdio.h>

// TP1 - Exercice 5
// Utilisation des opérateurs arithmétiques et logiques

int main() {
    int a = 16;
    int b = 3;

    printf("L'addition de %d et de %d est de %d \n", a, b, a+b);
    printf("La soustraction de %d par %d est de %d \n", a, b, a-b);
    printf("Le produit de %d et de %d est de %d \n", a, b, a*b);
    printf("La division entirere de %d par %d est de %d \n", a, b, a/b);
    printf("Le reste de la division de %d par %d est de %d \n", a, b, a%b);
    printf("L'affirmation ou %d et %d sont égaux est %d \n", a, b, a==b);
    printf("L'affirmation ou %d est surpérieur à %d est %d \n", a, b, a>b);
    return 0;
}