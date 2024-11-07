// TP4 Exercice 2
// Gestion de fichiers
/*
 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 * Fichier       : fichier.c
 * Description   :
 * Ce programme a pour but de gérer des fichiers en utilisant deux fonctions définies dans les fichiers fichier.c et fichier.h. 
 * Les fonctions requièrent le nom d'un fichier en entrée
 * La fonction lire_fichier affiche le contenu du fichier à l'écran
 * La fonction ecrire_dans_fichier permet à l'utilisateur de saisir un message qui sera ensuite enregistré dans le fichier.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"


int lire_fichier(const char* nom_de_fichier){
    FILE* fichier = fopen(nom_de_fichier, "r");  // Ouvre le fichier en mode lecture

    if (fichier == NULL)
        return 0;
    else {
        char ch;    // stocke chaque caractere un par un
        while ((ch = fgetc(fichier)) != EOF) {  // lire le fichier jusqu'à la fin du fichier
            putchar(ch);  // Affiche le contenu du fichier caractère par caractère
        }
        fclose(fichier);  // fermeture du fichier
        return 1;
    }
}


int ecrire_fichier(const char* nom_de_fichier, const char* message){
    FILE* fichier = fopen(nom_de_fichier, "a");  // ouvrie le fichier en mode écriture

    if (fichier == NULL) {
        return 0;
    }
    else{
        fprintf(fichier, "%s\n", message);  // écriture du message dans le fichier
        fclose(fichier);  // fermeture du fichier
        return 1;
    }
}