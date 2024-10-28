#include <stdio.h>
#include <stdlib.h>

// TP2 - Exercice 8
// Rechercher une phrase dans un tableau de phrases

int rechercherPhrase(int taille, char *tabPhrases[], char phrase[]){
    for (int i = 0; i < taille; i++){
        int j = 0;
        while(phrase[j] != '\0' && tabPhrases[i][j] != '\0'){
            if (phrase[j] != tabPhrases[i][j]) {
                break; 
            }
            j++;
        }
        // Vérification si toute la phrase recherchée a été trouvée et retourne vrai
        if (phrase[j] == '\0' && tabPhrases[i][j] == '\0') {
            return 1;
        }
    }
    return 0;
}

int main(){
    
    // creation tableau de 10 phrases
    int taille = 10;
    char *tabPhrases[10] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent être deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };

    // Phrase à chercher dans le tableau
    char *phrase = "Bonjour, comment ca va ?";
    //char *phrase2 = "Bonjour";
    
    // Test et affichage de la recherche
    if (rechercherPhrase(taille, tabPhrases, phrase)) {
        printf("Phrase trouvée : %s\n", phrase);
    } 
    else {
        printf("Phrase non trouvée : %s\n", phrase);
    }
}