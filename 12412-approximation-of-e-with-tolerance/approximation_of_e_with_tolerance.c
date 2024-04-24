#include <stdio.h>
#include <stdbool.h>


int main  (void) {

    float epsilon;

    printf("This program keeps approximating Euler's e using more terms until the\n");
    printf("last term is smaller than a user defined value epsilon: ");
    scanf(" %f", &epsilon);

    float e = 1.0f;

    int iterm = 1;

    while (true) {

        // factorial of iterm:
        int fact = 1;
        for (int i = iterm; i > 1; i--) {
            fact = fact * i;
        }

        float term =  1.0f / fact;

        if (term <= epsilon) {
            break;
        }

        e = e + term;

        iterm += 1;

    }

    printf("The number e is approximately equal to %.6f.\n", e);

    return 0;

}
