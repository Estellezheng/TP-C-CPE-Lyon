#include <stdlib.h>
#include <stdio.h>
#include "operator.h"

int main(int argc, char* argv[]){
    if (argc != 4) {
        printf("Erreur, trop ou pas assez d'argument \n");
        return 0; 
    }

    // Extraire les opérateurs et les nombres
    char operator = argv[1][0]; 
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);
    int resultat;

    // afficher les resultat
    switch (operator) {
        case '+':
            resultat = somme(num1, num2);
            break;
        case '-':
            resultat = difference(num1, num2);
            break;
        case '*':
            resultat = produit(num1, num2);
            break;
        case '/':
            resultat = quotient(num1, num2);
            break;
        case '%':
            resultat = modulo(num1, num2);
            break;
        case '&':
            resultat = et(num1, num2);
            break;
        case '|':
            resultat = ou(num1, num2);
            break;
        default:
            return 0;
    }

    printf("Résultat : %d\n", resultat);
}