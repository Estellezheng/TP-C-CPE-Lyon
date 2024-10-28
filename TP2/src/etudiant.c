#include <stdio.h>

// TP2 - Exercice 5
// Gestion des Données Étudiantes en C

int main() {
    char *noms[] = {"AA", "BB", "CC", "DD", "EE"};
    char *prenoms[] = {"Estelle", "bb", "cc", "dd", "ee"};
    char *adresses[] = {"9 rue du garet", "1 rue de la republique", "3 rue merciere", "4 rue de la doua", "6 rue charpenne"};

    int notesC[5] = {18, 15, 17, 13, 12};
    int notesSE[5] = {15, 13, 12, 13, 14};


    // Affichage des étudiants
    for (int i = 0; i < 5; i++) {
        printf("L'étudiant %d est %s %s, habite au %s et a eu %d en C et %d en système d'exploitation\n",
               i+1, noms[i], prenoms[i], adresses[i], notesC[i], notesSE[i]);
    }

    return 0;
}
