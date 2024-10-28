#include <stdio.h>

// TP1 - Exercice 8
// Utilisation de l'opérateur switch pour des opérations mathématiques


int main(){

    int num1 = 70;
    int num2 = 12;
    int resultat = 0;
    char op = '%';

    switch (op){
        case '+' :
            resultat = num1 + num2;
            break;
        case '-' :
            resultat = num1 - num2;
            break;
        case '*' :
            resultat = num1 * num2;
            break;
        case '/' :
            if (num2 != 0)
                resultat = num1 / num2;
            break;
        case '%' :
            resultat = num1 % num2;
            break;
        case '&' :
            resultat = num1 & num2;
            break;
        case '|' :
            resultat = num1 | num2;
            break;
        case '~':
            resultat = ~num1; 
            break;
        default:
            break;
    }

    // Affichage du résultat
    printf("L'opération de %d %c %d est égal à %d \n", num1, op, num2, resultat);

}
