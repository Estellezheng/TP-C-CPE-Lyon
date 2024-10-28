#include <stdio.h>


// TP4 - Exercice 5
// Calcul de la factorielle

// Définition de la fonction factorielle
int factorielle(int num) {
    if (num == 0) {
        printf("fact(0): 1\n");
        return 1;
    } 
    else {
        int valeur = num * factorielle(num - 1);
        printf("fact(%d): %d\n", num, valeur);
        return (valeur);
  }
}

int main() {
    int n = 5;
    // Testez la fonction factorielle avec différentes valeurs d'entiers naturels
    for (int i = 0; i <= n; i++) {
        printf("La factorielle de %d est %d\n", i, factorielle(i));
    }
    
    return 0;
}