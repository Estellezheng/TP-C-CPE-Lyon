#include "fichier.h"

// TP4 - Exercice 2
// Gestion de fichiers

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