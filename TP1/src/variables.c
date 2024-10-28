#include <stdio.h>

// TP1 - Exercice 4
// Affectation et affichage des variables de types de base

int main () {
    char lettre = 'a';
    char lettre_s = 100;
    short short_u= 32000;
    int int_u = 32000;
    long int long_int_u = 2000000;
    long long int long_long_int_u = 9223372036854775807;
    float float_ = 100.02;
    double double_ = 1000.02;
    long double long_double_ = 100000.2;

    printf("char : %c\n", lettre);
    printf("unsigned char : %hhu\n", lettre_s);
    printf("short %hd\n",short_u );
    printf("unsigned int %d\n", int_u);
    printf("unsigned long int est %lu \n", long_int_u);
    printf("unsigned long long int  %llu \n",long_long_int_u);
    printf("float %f\n", float_);
    printf("double %G\n", double_);
    printf("long double %LG \n", long_double_);
    return 0;
}