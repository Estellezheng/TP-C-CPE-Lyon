#include <stdio.h>

// TP1 - Exercice 10
// Génération d'une pyramide de nombres


int main(){

    int n = 6;  //hauteur
    int i, j;
    
    for (i = 1; i<=n; i++){     // chaque ligne
        for(j = 1; j<=n*2; j++){        // chaque colonne
            if (j<= n - i || j >= n + i)        // espaces
                printf(" ");
            if(j==n){
                for (int k =1; k<2*i; k++){     // chiffres croissants puis decroissants
                    if (k<=i)
                        printf("%d", k);
                    else 
                        printf("%d", 2*i-k);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
