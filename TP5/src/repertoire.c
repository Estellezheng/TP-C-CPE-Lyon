// TP5 Exercice 1 et Exercice 2
// 1. Liste de fichiers et repertoires dans un dossier
// 2. Liste récursive de fichiers et répertoires dans un dossier
/*
 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 * Fichier       : repertoire.c
 * Description   :
 * Version 1 : Le programme prend en entrée le nom d'un répertoire via l'interface en ligne de commande 
 * et affiche la liste des fichiers (et répertoires, le cas échéant) présents dans ce répertoire. 
 * Version 2 : Il utilise une fonction récursive pour parcourir tous les niveaux du répertoire.
 */

#include "repertoire.h"
#include <stdio.h>
#include <dirent.h> 
#include <string.h>


// Fonction pour lire le contenu d'un répertoire
void lire_dossier(const char *nom_repertoire) {
    // Ouvrir le répertoire
    DIR *dir = opendir(nom_repertoire);
    if (dir == NULL) {
        printf("Erreur lors de l'ouverture du répertoire");
    }
    else{
        // Lire et afficher les fichiers et répertoires dans le répertoire
        struct dirent *entree;
        while ((entree = readdir(dir)) != NULL) {
            printf("%s\n", entree->d_name);
        }
    }
    closedir(dir);  // Fermer le répertoire
}

void lire_dossier_recursif(const char *nom_repertoire){
    DIR *dir = opendir(nom_repertoire);
    if (dir == NULL) {
        printf("erreur de repertoire");
        return;
    }
    
    struct dirent *entree;
    while ((entree = readdir(dir)) != NULL) {
        // Ignorer les répertoires spéciaux "." et ".."
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }
        // Affiche le nom du fichier ou répertoire
        printf("%s/%s\n", nom_repertoire, entree->d_name);
        // Vérifier si c'est un répertoire pour faire la récursion
        if (entree->d_type == DT_DIR) {
            // Construire le chemin complet du sous-répertoire
            char chemin_complet[1024];
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", nom_repertoire, entree->d_name);
            // Appel récursif pour parcourir le sous-répertoire
            lire_dossier_recursif(chemin_complet);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    // exercice 1
    //const char *nom_repertoire = argv[1];
    //lire_dossier(nom_repertoire);

    // exercice 2
    char *nom_repertoire = argv[1];
    lire_dossier_recursif(nom_repertoire);

    return 0;
}