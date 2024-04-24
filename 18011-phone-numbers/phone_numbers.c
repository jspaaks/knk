#include <stdbool.h>
#include <stdio.h>


int main (void) {

    printf("Please enter a phone number: ");

    char phonenumber[15];
    int ichar = 0;
    int nchars;

    while (true) {

        int c = getchar();

        if (c == '\n') {
            break;
        }

        phonenumber[ichar] = c;
        ichar += 1;

    }

    nchars = ichar;

    printf("The numeric equivalent is  : ");

    for (int ichar = 0; ichar < nchars; ichar++) {

        char c = phonenumber[ichar];

        if (c == 'A' || c == 'B' || c == 'C') {
            putchar('2');
        } else if (c == 'D' || c == 'E' || c == 'F') {
            putchar('3');
        } else if (c == 'G' || c == 'H' || c == 'I') {
            putchar('4');
        } else if (c == 'J' || c == 'K' || c == 'L') {
            putchar('5');
        } else if (c == 'M' || c == 'N' || c == 'O') {
            putchar('6');
        } else if (c == 'P' || c == 'R' || c == 'S') {
            putchar('7');
        } else if (c == 'T' || c == 'U' || c == 'V') {
            putchar('8');
        } else if (c == 'W' || c == 'X' || c == 'Y') {
            putchar('9');
        } else {
            putchar(c);
        }
    }
    putchar('\n');
}
