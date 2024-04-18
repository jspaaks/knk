#include <stdio.h>

int main (void) {

    int input;
    printf("Please enter an integer number between 0 and 32767: ");
    scanf("%d", &input);

    int remaining = input;

    int pos0 = remaining % 8;
    remaining = remaining / 8;

    int pos1 = remaining % 8;
    remaining = remaining / 8;

    int pos2 = remaining % 8;
    remaining = remaining / 8;

    int pos3 = remaining % 8;
    remaining = remaining / 8;

    int pos4 = remaining % 8;
    remaining = remaining / 8;

    printf("%d in octal is: %d%d%d%d%d\n", input, pos4, pos3, pos2, pos1, pos0);

    return 0;

}
