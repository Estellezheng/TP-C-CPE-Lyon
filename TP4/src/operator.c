#include <stdlib.h>
#include <stdio.h>
#include "operator.h"

// TP4 - Exercice 1 
// Calcul avec opérateurs


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
