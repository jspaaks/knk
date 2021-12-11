#include <stdio.h>


int main (void) {

    int input;

    printf("Please enter a three-digit number: ");
    scanf("%d", &input);

    int remaining = input;

    int base100 = remaining / 100;
    remaining = remaining - base100 * 100;

    int base10 = remaining / 10;
    remaining = remaining - base10 * 10;

    int base1 = remaining;

    printf("Reversed: %d%d%d\n", base1, base10, base100);

    return 0;

}
