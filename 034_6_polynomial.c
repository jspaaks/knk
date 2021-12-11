#include <stdio.h>


int main(void) {

    float x, y;
    printf("Enter a value for x: ");
    scanf("%f", &x);

    // 3x^5 + 2x^4 - 5x^3 - x^2 + 7x

    y = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("Result: %.2f\n", y);
}
