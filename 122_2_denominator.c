#include <stdio.h>


int main (void) {

    // implementation of Euclid's algorithm for finding the greatest common denominator.

    int m0;
    int n0;

    printf("Please enter two integer numbers separated by a space: ");
    scanf(" %d %d", &m0, &n0);

    int m = m0;
    int n = n0;
    int tmp;

    while (n != 0) {
        tmp = m % n;
        m = n;
        n = tmp;
    }

    printf("The greatest common denominator of %d and %d is %d.\n", m0, n0, m);

    return 0;

}
