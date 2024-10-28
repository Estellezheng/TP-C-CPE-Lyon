#include <stdio.h>

// TP2 - Exercice 7
// Gestion des Couleurs en Format RGBA avec des Structures


int main(){
    struct RGBA {
        int rouge;
        int vert;
        int bleu;
        int alpha;
    };
    
    struct RGBA C1 = {0xef, 0x78, 0x12, 0xff};
    struct RGBA C2 = {0xab, 0x21, 0x53, 0x00};
    struct RGBA C3 = {0x46, 0xbc, 0x33, 0x80};
    struct RGBA C4 = {0x72, 0x21, 0xc3, 0xaa};
    struct RGBA C5 = {0x54, 0x22, 0x63, 0xbb};

    struct RGBA tabCouleurs[5] = {C1, C2, C3, C4, C5};  // tableau de strcture de couleurs

    // Affichage des couleurs
    for (int i = 0; i < 5; i++) {
        printf("Couleur %d : \nRouge : %d\nVert : %d \nBleu : %d \nAlpha : %d\n\n",
               i+1, tabCouleurs[i].rouge, tabCouleurs[i].vert, tabCouleurs[i].bleu, tabCouleurs[i].alpha);
    }
   
}