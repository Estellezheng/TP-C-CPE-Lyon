#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"


int main(int argc, char *argv[]){
    
    // Exercice 1 : Calcul avec operateur
    if (argc > 1 && strcmp(argv[1], "1") == 0){
        int num1, num2, resulat;
        char op;

        printf("Entrer num1 : ");
        scanf("%d",&num1);
        printf("Entrer num2 : ");
        scanf("%d",&num2);
        printf("Entrez l'opérateur (+, -, *, /, &, |, ~) : ");
        scanf(" %c",&op);

        switch (op){
        case '+' : 
            resulat = somme(num1,num2);
            break;
        case '-' : 
            resulat = difference(num1,num2);
            break;
        case '*' : 
            resulat = produit(num1,num2);
            break;
        case '/' : 
            resulat = quotient(num1,num2);
            break;
        case '%' : 
            resulat = modulo(num1,num2);
            break;
        case '&' : 
            resulat = et(num1,num2);
            break;
        case '|' : 
            resulat = ou(num1,num2);
            break;
        default:
            break;
        }

        printf("Le resulat est %d. \n\n", resulat);
    }

    // EXO 2 : gestion des fichiers

    if (argc > 1 && strcmp(argv[1], "2") == 0){
        int choix;
        char nom_de_fichier [10];   // fichier existant texte
        char message[100];

        printf("Que souhaitez-vous faire ?\n1. Lire un fichier\n2. Écrire dans un fichier\nVotre choix : ");
        scanf("%d",&choix);
        getchar();

        // Choix de lecture du fichier
        if (choix == 1) {
            printf("Entrez le nom du fichier à lire : ");
            // 1ere methode
            scanf("%s",nom_de_fichier);
            getchar();
            // 2e methode
            //fgets(nom_de_fichier, sizeof(nom_de_fichier), stdin);     
            //nom_de_fichier[strcspn(nom_de_fichier, "\n")] = '\0';  
            printf("Contenu du fichier '%s.txt' : ", nom_de_fichier);
            if(lire_fichier(nom_de_fichier) == 0)     // lecture du fichier ou erreur
                printf("Le fichier %s n'a pas été trouvé.\n", nom_de_fichier);
        }

        // Choix d'ecriture du message dans le fichier
        else if (choix == 2) {
            printf("Entrez le nom du fichier à lire :");
            scanf("%s",nom_de_fichier);
            printf("Entrez le message à écrire:");
            scanf("%s",message);

            if(ecrire_fichier(nom_de_fichier, message))
                printf("Le message a été écrit dans le fichier '%s.txt'.", nom_de_fichier);
            else {
                printf("Le message a été écrit dans le fichier '%s.txt'.\n", nom_de_fichier);
            }
        }
    }

    // EXO 3 : Liste simplement chainé de couleurs

    if (argc > 1 && strcmp(argv[1], "7") == 0){
        struct liste_couleurs ma_liste;
        init_liste(&ma_liste);

        struct couleur couleur1 = {0xFF, 0x00, 0x00, 0xFF, NULL}; // Exemple de couleur (rouge)
        struct couleur couleur2 = {0x00, 0xFF, 0x00, 0xFF, NULL}; // Exemple de couleur (vert)
        struct couleur couleur3 = {0x00, 0xFF, 0x03, 0xFF, NULL};
        struct couleur couleur4 = {0x04, 0xFF, 0x00, 0xFF, NULL};
        struct couleur couleur5 = {0x05, 0xFF, 0x05, 0xFF, NULL};

        insertion(&couleur1, &ma_liste);
        insertion(&couleur2, &ma_liste);
        insertion(&couleur3, &ma_liste);
        insertion(&couleur4, &ma_liste);
        insertion(&couleur5, &ma_liste);

        printf("Liste des couleurs :\n");
        parcours(&ma_liste);
    }

}

  