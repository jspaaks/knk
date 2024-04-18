#include <stdio.h>


int main(void) {

    float x, y;
    printf("Enter a value for x: ");
    scanf("%f", &x);

    // 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

    y = 3 * x * x * x * x * x +
        2 * x * x * x * x +
       -5 * x * x * x +
       -1 * x * x +
        7 * x +
       -6;

    printf("Result: %.2f\n", y);
}
