#include <stdio.h>

int main (void) {

    int input;
    printf("Please enter a number between 0 and 32767: ");
    scanf("%d", &input);
    printf("The octal representation of %d in octal is: %05o\n", input, input);
    return 0;

}
