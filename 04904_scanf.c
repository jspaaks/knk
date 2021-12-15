#include <stdio.h>

int main (void) {

    int i, j;
    float x, y;
    printf("Enter the following exactly as-is:\n");
    printf("10.3 5 6\n");
    scanf("%d%f%d", &i, &x, &j);

    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("x = %.1f\n", x);
    printf("y = %.1f\n", y);
}
