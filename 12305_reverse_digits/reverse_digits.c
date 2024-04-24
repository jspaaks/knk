#include <stdio.h>


int main (void) {

    int input;

    printf("Please enter an integer number: ");
    scanf("%d", &input);

    int remaining = input;
    int last_digit;

    printf("Reversed: ");

    do {
        last_digit = remaining % 10;
        remaining = remaining / 10;
        printf("%d", last_digit);
    } while (remaining != 0);

    printf("\n");

    return 0;

}
