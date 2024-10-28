#include <stdio.h>

// TP2 - Exercice 6
// Gestion des Données d'Étudiant.e.s en C avec des Structures

int main(){

    struct Etudiant {
        char nom[20];
        char prenom[20];
        char adresse[40];
        int noteC;
        int noteSE;
    };
    
    // definition des différents étudiants
    struct Etudiant E1 = {"AA", "Estelle", "9 rue du garet", 18, 15};
    struct Etudiant E2 = {"BB", "bb", "1 rue de la republique", 15, 13};
    struct Etudiant E3 = {"CC", "cc", "3 rue merciere", 12, 11};
    struct Etudiant E4 = {"DD", "dd", "4 rue de la doua", 13, 15};
    struct Etudiant E5 = {"EE", "ee", "6 rue charpenne", 17, 14};

    // Tableau de structure d'étudiants 
    struct Etudiant tabEtudiant[5] = {E1, E2, E3, E4, E5}; 
    
    // Affichage des étudiants
    for (int i = 0; i < 5; i++) {
        printf("Etudiant.e %d : \nNom : %s\nPrenom : %s \nAdresse : %s \nNote 1 : %d \nNote 2 : %d\n\n",
               i+1, tabEtudiant[i].nom, tabEtudiant[i].prenom, tabEtudiant[i].adresse, tabEtudiant[i].noteC, tabEtudiant[i].noteSE);
    }
}