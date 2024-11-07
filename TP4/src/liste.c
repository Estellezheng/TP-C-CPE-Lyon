// TP4  Exercice 7
// Gestion d'une liste de couleurs
/*
 * Auteur(s)     : Juliette Tardy et Estelle Zheng
 * Fichier       : liste.c
 * Description   :
 * Le programme permet de gérer une liste (simplement chaînée) de couleurs RGB. 
 * deux fonctions principales : insertion pour ajouter une couleur à la liste et parcours pour afficher toutes les couleurs de la liste.
 */

#include "liste.h"
#include <stdio.h>
#include <stdlib.h>


// Initialise la liste avec une tête NULL
void init_liste(struct liste_couleurs* ma_liste){
    ma_liste->tete = NULL;
}

// Insertion d'une nouvelle couleur à la fin de la liste
void insertion(struct couleur* couleur_nouvelle, struct liste_couleurs* ma_liste){
    struct couleur* nouveau = (struct couleur*)malloc(sizeof(struct couleur));
    if (nouveau == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    *nouveau = *couleur_nouvelle;
    nouveau->next = NULL;

    if (ma_liste->tete == NULL) {   // liste vide donc premier élement
        ma_liste->tete = nouveau;
    }
    else{
        struct couleur* couleur_actuelle = ma_liste->tete;
        while (couleur_actuelle->next != NULL) {
            couleur_actuelle = couleur_actuelle->next;
        }
        couleur_actuelle->next = nouveau;

    }
}

// Parcour et affiche la liste depuis la tete
void parcours(struct liste_couleurs* ma_liste){
    struct couleur* couleur_actuelle = ma_liste->tete;
    while (couleur_actuelle != NULL) {
        printf("Couleur : Rouge : %02X, Vert : %02X, Bleu : %02X, Alpha : %02X\n", couleur_actuelle->rouge, couleur_actuelle->vert, couleur_actuelle->bleu, couleur_actuelle->alpha);
        couleur_actuelle = couleur_actuelle->next;
    }
}