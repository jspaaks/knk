#include <stdio.h>


int main (void) {

    int i2, i1, i0;
    printf("Please enter a three-digit number: ");
    scanf("%1d%1d%1d", &i2, &i1, &i0);
    printf("Reversed: %d%d%d\n", i0, i1, i2);

    return 0;

}
