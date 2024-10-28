#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// TP3 - Exercice 7
// Compter les couleurs distinctes dans un tableau

const int TAILLE = 100;
const int MAX = 255, MIN = 1;   // plage de valeurs pour une couleur


// Structure couleur
struct RGBA {
    int rouge, vert, bleu, alpha;
};

// Structure couleurs distincte
struct couleursDistinctes{
    struct RGBA couleur;
    int cpt;        // nombre d'occurences de cette couleur
};


// fonction qui compare si ce sont les memes couleurs
bool comparerCouleurs(struct RGBA c1, struct RGBA c2) {
    return (c1.rouge == c2.rouge && c1.vert == c2.vert && c1.bleu == c2.bleu && c1.alpha == c2.alpha);
}


int main(){
    srand(time(NULL));

    // Création aletoire du tableau de 100 couleurs
    struct RGBA tabCouleurs[100];
    for (int i = 0; i < TAILLE; i++){
        tabCouleurs[i].rouge = (rand() % (MAX - MIN + 1)) + MIN;
        tabCouleurs[i].vert = 1;//(rand() % (MAX - MIN + 1)) + MIN; // pour avoir une meilleur probabilité de meme couleur
        tabCouleurs[i].bleu = 1;//(rand() % (MAX - MIN + 1)) + MIN;
        tabCouleurs[i].alpha = 1;
    }

    // Creation du tableau couleurs distinctes
    struct couleursDistinctes tabCouleursDistinctes[100];     
    int cptTabDistinct = 0;     // taille du tableau de couleurs distinctes

    // Compte le nombre de couleurs distinctes
    for (int i = 0; i<TAILLE; i++){     // parcourt chaque couleur du tab de base
        struct RGBA couleurActuelle = tabCouleurs[i];
        bool isExist = false;

        // parcourt le tableau de couleurs distinctes 
        for (int j = 0; j < cptTabDistinct; j++) {
            // si la couleur existe déjà dans le tab de couleurs distinctes on incrémente le compteur
            if (comparerCouleurs(couleurActuelle, tabCouleursDistinctes[j].couleur)) {
                tabCouleursDistinctes[j].cpt++;
                isExist = true;
                break;
            }
        }

        // Si la couleur n'existe pas dans le tab de couleurs distincte, on l'ajoute dans le tableau
        if (!isExist) {
            tabCouleursDistinctes[cptTabDistinct].couleur = couleurActuelle;
            tabCouleursDistinctes[cptTabDistinct].cpt = 1;
            cptTabDistinct++;
        }
    }


    // Affichage 
    printf("Couleurs distinctes : nombre d'occurrences :\n");
    for (int i = 0; i < cptTabDistinct; i++) {
        struct RGBA c = tabCouleursDistinctes[i].couleur;
        printf("0x%02x 0x%02x 0x%02x 0x%d : %d\n", c.rouge, c.vert, c.bleu, c.alpha, tabCouleursDistinctes[i].cpt);
    }

}