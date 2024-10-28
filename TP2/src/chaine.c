#include <stdio.h>

// TP2 - Exercice 4
// Manipulation de Chaînes de Caractères en C

// effectue trois opérations de base sur des chaînes de caractères, le tout sans utiliser de bibliothèques standard ou externes :

int calculerLongueur(char *mot){
    int longueur = 0;
    while (mot[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}


void copierChaine(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';  
}


void concatenation(char *destination, const char *source) {
    int longueur = calculerLongueur(destination);
    int i = 0;
    while (source[i] != '\0') {
        destination[longueur + i] = source[i];
        i++;
    }
    destination[longueur + i] = '\0';  
}

int main() {
    char mot1[20] = "Hello";
    char mot2[20] = "World";
    char copie[40]; 

    // Calcul de la longueur de la première chaîne
    printf("La chaine de caracteres %s possède %d caractere\n",mot1, calculerLongueur(mot1));

    // Copie d"une chaîne dans une autre chaîne
    copierChaine(copie, mot2);
    printf("Copie de la deuxieme chaine dans copie : %s\n", copie);

    // Concatenation des deux chaînes
    concatenation(mot1, mot2);  // Puis ajouter la deuxième chaîne
    printf("Résultat de la concaténation : %s\n", mot1);

    return 0;
}


