#include <stdio.h>


int main (void) {

    int input;
    printf("Please enter a two-digit number: ");
    scanf("%d", &input);
    printf("Reversed: %d%d\n", input % 10, input / 10);

    return 0;

}
