// TP4 Exercice 3
// Gestion d'une base de données étudiante
/*
 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 * Fichier       : etudiant_bd.c
 * Description   :
 * Ce programme permet de gérer une base de données d'étudiants 
 * en enregistrant leurs noms, prénoms, adresses et notes dans un fichier texte etudiant.txt. 
 * L'utilisateur est invité à fournir les détails de chaque étudiant via scanf, 
 * et ces informations sont ensuite stockées dans le fichier etudiant.txt.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"


struct Etudiant {
    char nom[10];
    char prenom[10];
    char adresse[40];
    int note1;
    int note2;
};

int main(){
    // Tableau d'etudiants
    struct Etudiant tabEtudiant[2];

    // saisie des infos par l'utilisateur
    int nbEtudiants = 2;
    for (int i=0; i<nbEtudiants; i++){
        printf("\nEntrez les détails de l'étudiant.e %d:\nNom : ", i+1);
        scanf("%s",tabEtudiant[i].nom);
        getchar();
        printf("Prenom : ");
        scanf("%s",tabEtudiant[i].prenom);
        getchar();
        printf("Adresse : ");
        scanf("%[^\n]",tabEtudiant[i].adresse);     // %[^\n] pour prendre ne compte toute le chaine
        getchar();
        printf("Note1 : ");
        scanf("%d",&tabEtudiant[i].note1);
        getchar();
        printf("Note2 : ");
        scanf("%d",&tabEtudiant[i].note2);
        getchar();
    }

    // Ecriture dans le fichier etudiant.txt
    char nom_de_fichier[10] = "etudiants";
    char message[1000];

    for (int j=0; j<nbEtudiants; j++){
        sprintf(message, "Nom: %s, Prenom: %s, Adresse: %s, Note1: %d, Note2: %d\n",
        tabEtudiant[j].nom, tabEtudiant[j].prenom, tabEtudiant[j].adresse,
        tabEtudiant[j].note1, tabEtudiant[j].note2);    // formate la chaine dans le tablau char

        if (ecrire_fichier(nom_de_fichier, message)) 
            printf("Les détails des étudiants ont été enregistrés dans le fichier etudiant.txt\n");
        else 
            printf("Erreur, les détails de l'etudiant n'ont pas pu etre enregistrés");
    }
}

