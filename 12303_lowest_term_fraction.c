#include <stdio.h>


int main (void) {

    int enum0;
    int denom0;

    printf("Enter a number as a fraction: ");
    scanf(" %d / %d", &enum0, &denom0);

    // Euclid's algorithm for finding the greatest common denominator (gcd):
    int n = enum0;
    int m = denom0;
    int tmp;

    while (n != 0) {
        tmp = m % n;
        m = n;
        n = tmp;
    }

    int gcd = m;

    printf("%d/%d in lowest terms is: %d/%d.\n", enum0, denom0, enum0 / gcd, denom0 / gcd);

    return 0;

}
