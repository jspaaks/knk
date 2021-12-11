#include <stdio.h>

int main (void) {

    int i;
    float x;
    float y;

    printf("Enter the following exactly as-is:\n");
    printf("12.3 45.6 789\n");
    scanf("%f%d%f", &x, &i, &y);
    printf("i = %d\n", i);
    printf("x = %.1f\n", x);
    printf("y = %.1f\n", y);

    return 0;
}
