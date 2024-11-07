// TP4 Exercice 6
// Recherche de phrases dans un fichier
/*
 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 * Fichier       : chercherfichier.c
 * Description   :
 * Le programme permet à l'utilisateur de rechercher une phrase dans un fichier donné. 
 * Le programme affiche les lignes du fichier où la phrase est présente, 
 * ainsi que le nombre de fois qu'elle apparaît dans chaque ligne
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){

    // Demande à l'utilisateur de saisir le nom du fichier
    char nom_de_fichier [10];
    printf("Saisissez le nom du fichier : ");  // chercherPhrase
    scanf("%s",nom_de_fichier);
    getchar();

    // Demande à l'utilisateur de saisir la phrase qu'il souhaite chercher
    char phrase [100];
    printf("Saisissez la phrase à chercher : ");
    scanf("%s",phrase);
    getchar();

    // Ouverture du fichier
    FILE* fichier = fopen(nom_de_fichier, "r");  

    if (fichier == NULL)    // erreur
        printf("Erreur avec le fichier");

    else {
        printf("Resultat de la recherche :\n");
        char ligne[50];  // Tableau pour stocker chaque ligne
        int cpt = 0;    // compteur ou la phrase apparait pour chaque ligne
        int nLigne = 0;
        int existe = 0;

        while (fgets(ligne, sizeof(ligne), fichier)) {      // fgets lit chaque ligne
            nLigne++;  
            cpt = 0;
            char* position = ligne;
            
            while ((position = strstr(position, phrase)) != NULL) {  // strstr cherche la sous chaine phrase dans la chaine pointée par position sinon renvoie NULL
                cpt++;
                position += strlen(phrase);  // position pointe après la phrase trouvée
                existe = 1; 
            }
            
            if (cpt > 0)
                printf("Ligne %d, %d fois\n", nLigne, cpt);
        }
        if (existe == 0)
            printf("La phrase n'est pas presente dans le fichier\n");

        fclose(fichier);  // fermeture du fichier
        }

    // Exemple
    /*
    Saisissez le nom du fichier : chercherPhrase
    Saisissez la phrase à chercher : Exercice 6
    Resultat de la recherche :
    Ligne 1, 1 fois
    Ligne 10, 2 fois      
    */  

}