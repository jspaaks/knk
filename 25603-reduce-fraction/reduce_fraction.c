#include <stdio.h>


void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);


int main (void) {

    int numer;
    int denom;

    printf("Enter a number as a fraction: ");
    scanf(" %d / %d", &numer, &denom);

    int numer_reduced;
    int denom_reduced;

    reduce(numer, denom, &numer_reduced, &denom_reduced);

    printf("%d/%d in lowest terms is: %d/%d.\n", numer, denom, numer_reduced, denom_reduced);

    return 0;

}


void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {

    // Euclid's algorithm for finding the greatest common denominator (gcd):
    int n = numerator;
    int m = denominator;
    int tmp;

    while (n != 0) {
        tmp = m % n;
        m = n;
        n = tmp;
    }

    int gcd = m;

    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;

    return;
}
