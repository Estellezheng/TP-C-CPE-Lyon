#include <stdio.h>

// TP1 - Exercice 7
// Conditions et boucles avec divisibilité

int main(){

    int somme = 0;
    
    for(int i = 1; i<=1000; i++){
        if (i%5 == 0 || i%7==0){
            somme += i;
        }
        if (i%11== 0){
            continue;
        }
        if(somme > 5000){
            printf("La somme finale est de %d \n", somme);
            break;
        }
    }
    printf("La somme finale est de %d \n", somme);
    return 0;
}