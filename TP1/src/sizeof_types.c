#include <stdio.h>

// TP1 - Exercice 3
// Tailles des types de base

int main (){
    printf("La taille d'un char est %lu octet\n", sizeof(char));
    printf("La taille d'un short est %lu octets\n", sizeof(short));
    printf("La taille d'un unsigned int est %lu octets\n", sizeof(unsigned int));
    printf("La taille d'un signed int est %lu octets\n", sizeof(signed int));
    printf("La taille d'un unsigned long int est %lu octets\n", sizeof(unsigned long int));
    printf("La taille d'un signed long int est %lu octets\n", sizeof(signed long int));
    printf("La taille d'un unsigned long long int est %lu octets\n", sizeof(unsigned long long int));
    printf("La taille d'un signed long long int est %lu octets\n", sizeof(signed long long int));
    printf("La taille d'un float est %lu octets\n", sizeof(float));
    printf("La taille d'un double est %lu octets\n", sizeof(double));
    printf("La taille d'un long double est %lu octets\n", sizeof(long double));
    
    return 0;
}