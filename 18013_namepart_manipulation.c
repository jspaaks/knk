#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int main (void) {

    printf("Enter a first and last name separated by a space: ");

    char initial;

    // read the initial
    while (true) {

        char c = toupper(getchar());

        if (c == '\n') {
            printf("No name entered, aborting.\n");
            return 1;
        } else if (c == ' ') {
            continue;
        } else if ('A' <= c && c <= 'Z') {
            initial = c;
            break;
        } else {
            printf("Unrecognized symbol, aborting.\n");
            return 1;
        }
    }

    // skip over the rest of the first name
    while (getchar() != ' ') {
        continue;
    }


    // read in the last name
    char lastname[20];
    int ichar = 0;

    while (true) {

        char c = getchar();

        if (c == '\n') {
            break;
        }

        lastname[ichar] = ichar == 0 ? toupper(c) : c;
        ichar += 1;

    }
    // store number of chars read
    int nchars = ichar;

    // remove trailing spaces
    for (int ichar = nchars - 1; ichar > 0; ichar--) {
        if (lastname[ichar] == ' ') {
            nchars = ichar;
        } else {
            break;
        }
    }

    printf("You entered the name: ");
    for (int ichar = 0; ichar < nchars; ichar++) {
        putchar(lastname[ichar]);
    }

    printf(", %1c.\n", initial);

    return 0;

}

