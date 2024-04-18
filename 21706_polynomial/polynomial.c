#include <stdio.h>


double polynomial(double x);


double polynomial(double x) {

   return 3 * x * x * x * x * x +
          2 * x * x * x * x +
         -5 * x * x * x +
         -1 * x * x +
          7 * x +
         -6;

}


int main (void) {

    printf("Enter a number: ");
    double x;
    scanf(" %lf", &x);

    double y = polynomial(x);
    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %.3f\n", y);

    return 0;

}
