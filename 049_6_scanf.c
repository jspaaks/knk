#include <stdio.h>

int main (void) {

    int denominator;
    int enumerator;
    printf("Enter a number as a fraction like 1 / 2: ");
    scanf("%d / %d", &enumerator, &denominator);
    printf("Entered: %d/%d\n", enumerator, denominator);
    return 0;
}
