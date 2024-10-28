#include <stdio.h>

// TP2 - Exercice 2 
// Vérification des Bits en C

/**vérifie si les 4ème et 20ème bits de gauche d'une variable 
entière d sont à 1 en représentation binaire. Si les deux bits sont 1, 
le programme doit afficher 1 ; sinon, il doit afficher 0. */

int main() {
    int d = 4145728;  // 0011 1111 0100 0010 0100 0000 ou 0b001111110100001001000000

    int mask4 = 1 << 3; 
    int bit4 = 0;
    if (d & mask4) {bit4 = 1;}

    int mask20 = 1 << 19; 
    int bit20 = 0;
    if (d & mask20) {bit20 = 1;}

    printf("bit4 = %d, bit20 = %d", bit4, bit20);
}