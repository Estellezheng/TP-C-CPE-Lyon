// TP4 - Exercice 1 
// Calcul avec opérateurs
/*
 * Fichier       : operator.c
 * Description   :
 * en utilisant des fichiers d'en-tête et de code source distincts. 
 * Les opérations  (somme, différence, produit, quotient, modulo, 'et', ou, négation) seront effectuées sur deux variables : num1 et num2. 
 * La sélection de l'opérateur se fera à l'aide d'une variable op contenant l'un des différents opérateurs (+, -, *, /, %, &, |, ~). 
 * Le programme principal testera ces fonctions avec différentes valeurs de num1, num2 et op.

 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 */

#include <stdlib.h>
#include <stdio.h>
#include "operator.h"

// Definition des fonctions

int somme (int num1, int num2){
    return num1 + num2;
}

int difference (int num1, int num2){
    return num1 - num2;
}

int produit (int num1, int num2){
    return num1 * num2;
}

int quotient (int num1, int num2){
    if (num2 != 0) 
        return num1 / num2;
    else 
        return 0;
}

int modulo (int num1, int num2){
    return num1 % num2;
}

int et(int num1, int num2) {
    return num1 & num2;
}

int ou(int num1, int num2) {
    return num1 | num2;
}

int negation(int num1) {
    return ~num1;
}
