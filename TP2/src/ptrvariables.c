#include <stdio.h>

int main() {
    // Variables
    char char_var = 'a';
    unsigned char uchar_var = 10;
    short short_var = -21;
    unsigned short ushort_var = 425;
    int int_var = -45;
    unsigned int uint_var = 52;
    long int lint_var = -45123L;
    unsigned long int ulint_var = 52652UL;
    long long int llint_var = -4512245565862LL;
    unsigned long long int ullint_var = 5245255635ULL;

    float float_var = -20.45;
    double double_var = 454.20;
    long double ldouble_var = 4567.22;

    // Pointeurs
    char *ptr_char = &char_var;
    unsigned char *ptr_uchar = &uchar_var;
    short *ptr_short = &short_var;
    unsigned short *ptr_ushort = &ushort_var;
    int *ptr_int = &int_var;
    unsigned int *ptr_uint = &uint_var;
    long int *ptr_lint = &lint_var;
    unsigned long int *ptr_ulint = &ulint_var;
    long long int *ptr_llint = &llint_var;
    unsigned long long int *ptr_ullint = &ullint_var;

    float *ptr_float = &float_var;
    double *ptr_double = &double_var;
    long double *ptr_ldouble = &ldouble_var;

    // Affichage des adresses et des valeurs avant manipulation
    printf("Avant manipulation :\n");

    printf("Adresse de char_var : %p, Valeur : %c\n", ptr_char, *ptr_char);
    printf("Adresse de uchar_var : %p, Valeur : %hhu\n", ptr_uchar, *ptr_uchar);
    printf("Adresse de short_var : %p, Valeur : %hd\n", ptr_short, *ptr_short);
    printf("Adresse de ushort_var : %p, Valeur : %hu\n", ptr_ushort, *ptr_ushort);
    printf("Adresse de int_var : %p, Valeur : %d\n", ptr_int, *ptr_int);
    printf("Adresse de uint_var : %p, Valeur : %u\n", ptr_uint, *ptr_uint);
    printf("Adresse de lint_var : %p, Valeur : %ld\n", ptr_lint, *ptr_lint);
    printf("Adresse de ulint_var : %p, Valeur : %lu\n", ptr_ulint, *ptr_ulint);
    printf("Adresse de llint_var : %p, Valeur : %lld\n", ptr_llint, *ptr_llint);
    printf("Adresse de ullint_var : %p, Valeur : %llu\n", ptr_ullint, *ptr_ullint);

    printf("Adresse de float_var : %p, Valeur : %f\n", ptr_float, *ptr_float);
    printf("Adresse de double_var : %p, Valeur : %g\n", ptr_double, *ptr_double);
    printf("Adresse de ldouble_var : %p, Valeur : %Lg\n\n", ptr_ldouble, *ptr_ldouble);

    // Manipulation des variables avec les pointeurs
    *ptr_char = 'z';
    *ptr_uchar = 46;
    *ptr_short = -100;
    *ptr_ushort = 576;
    *ptr_int = 100;
    *ptr_uint = 48;
    *ptr_lint = 384353L;
    *ptr_ulint = 3512121L;
    *ptr_llint = 4653544865LL;
    *ptr_ullint = 46511210513LL;

    *ptr_float = 543.1;
    *ptr_double = 2468.46;
    *ptr_ldouble = 54487.135;

    // Affichage des adresses et des valeurs après manipulation
    printf("Apres manipulation :\n");

    printf("Adresse de char_var : %p, Valeur : %c\n", ptr_char, *ptr_char);
    printf("Adresse de uchar_var : %p, Valeur : %hhu\n", ptr_uchar, *ptr_uchar);
    printf("Adresse de short_var : %p, Valeur : %hd\n", ptr_short, *ptr_short);
    printf("Adresse de ushort_var : %p, Valeur : %hu\n", ptr_ushort, *ptr_ushort);
    printf("Adresse de int_var : %p, Valeur : %d\n", ptr_int, *ptr_int);
    printf("Adresse de uint_var : %p, Valeur : %u\n", ptr_uint, *ptr_uint);
    printf("Adresse de lint_var : %p, Valeur : %ld\n", ptr_lint, *ptr_lint);
    printf("Adresse de ulint_var : %p, Valeur : %lu\n", ptr_ulint, *ptr_ulint);
    printf("Adresse de llint_var : %p, Valeur : %lld\n", ptr_llint, *ptr_llint);
    printf("Adresse de ullint_var : %p, Valeur : %llu\n", ptr_ullint, *ptr_ullint);
    
    printf("Adresse de float_var : %p, Valeur : %f\n", ptr_float, *ptr_float);
    printf("Adresse de double_var : %p, Valeur : %g\n", ptr_double, *ptr_double);
    printf("Adresse de ldouble_var : %p, Valeur : %Lg\n\n", ptr_ldouble, *ptr_ldouble);

    return 0;
}