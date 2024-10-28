// TP 4 - Exercice 7
// Gestion d'une liste de couleurs

#ifndef LISTE_H
#define LISTE_H


// Structure pour la liste de couleurs
struct couleur {
    int rouge, vert, bleu, alpha;
    struct couleur *next;
};

// Structure pour la liste de couleurs
struct liste_couleurs {
    struct couleur* tete;
    int cpt;
};

// Fonction pour initialiser la liste de couleurs
void init_liste(struct liste_couleurs* ma_liste);

// Fonction pour insérer une nouvelle couleur dans la liste
void insertion(struct couleur* nouvelle_couleur, struct liste_couleurs* ma_liste);

// Fonction pour parcourir la liste et afficher les couleurs
void parcours(struct liste_couleurs* ma_liste);

#endif
