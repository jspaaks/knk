#include <stdio.h>
#include <stdbool.h>


#define MAXLENGTH 1000


int main (void) {

    printf("Enter message to be encrypted: ");

    char msg[MAXLENGTH];
    int nchars;

    for (int ichar = 0; ichar < MAXLENGTH; ichar++) {

        char c = getchar();

        if (c == '\n') {
            nchars = ichar;
            break;
        } else {
            msg[ichar] = c;
        }

    }

    printf("Enter shift amount (1-25): ");

    int shift;

    scanf(" %d", &shift);

    if (shift < 0 || shift > 25) {
        printf("Shift amount should be between 1 and 25 characters. Aborting.\n");
        return 1;
    }

    printf("Encrypted message: ");

    for (int ichar = 0; ichar < nchars; ichar++) {

        char c = msg[ichar];
        char c_cipher;

        bool is_upper = 'A' <= c && c <= 'Z';
        bool is_lower = 'a' <= c && c <= 'z';

        if (is_upper == true) {
            c_cipher = (c - 'A' + shift) % 26 + 'A';
        } else if (is_lower == true) {
            c_cipher = (c - 'a' + shift) % 26 + 'a';
        } else {
            c_cipher = c;
        }

        putchar(c_cipher);

    }

    putchar('\n');

    return 0;

}
