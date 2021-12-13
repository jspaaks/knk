#include <stdio.h>


int main  (void) {

    int nterms;

    printf("This program approximates Euler's e using n terms.\n");
    printf("Please enter a positive integer for n: ");
    scanf(" %d", &nterms);

    float e = 1.0f;

    for (int iterm = 1; iterm <= nterms; iterm++) {

        // factorial of iterm:
        int fact = 1;
        for (int i = iterm; i > 1; i--) {
            fact = fact * i;
        }

        e = e + 1.0f / fact;

    }

    printf("The number e is approximately equal to %.6f.\n", e);

    return 0;

}
