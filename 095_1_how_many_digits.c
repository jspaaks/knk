#include <stdio.h>


int main (void) {

    int user_input;
    printf("Enter a number between 0 and 9999: ");
    scanf(" %4d", &user_input);

    int ndigits;

    if (user_input < 10) {
        ndigits = 1;
    } else if (user_input < 100) {
        ndigits = 2;
    } else if (user_input < 1000) {
        ndigits = 3;
    } else {
        ndigits = 4;
    }

    printf("Your number %d has %d %s.\n", user_input, ndigits, ndigits == 1 ? "digit" : "digits");

    return 0;

}
