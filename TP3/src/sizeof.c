#include <stdio.h>

// TP3 - Exercice 1
// Comprendre la taille des types de données

int main() {
    
    printf("La taille de int est : %lu octets\n", sizeof(int));
    printf("La taille de int* est : %lu octets\n", sizeof(int*));
    printf("La taille de int** est : %lu octets\n", sizeof(int**));
    printf("La taille de char* est : %lu octets\n", sizeof(char*));
    printf("La taille de char** est : %lu octets\n", sizeof(char**));
    printf("La taille de char*** est : %lu octets\n", sizeof(char***));
    printf("La taille de float* est : %lu octets\n", sizeof(float*));
    printf("La taille de float** est : %lu octets\n", sizeof(float**));
    printf("La taille de float*** est : %lu octets\n", sizeof(float***));
}
