#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLENGTH 1000


int main (void) {

    // prompt the user for input
    printf("Enter a sentence: ");

    // read the sentence into an array
    char sentence[MAXLENGTH];
    int ichar = 0;
    char terminator;
    char c_prev = ' ';
    int iwordstart[MAXLENGTH];
    int iwordend[MAXLENGTH];
    int iword = 0;

    while (true) {

        char c = getchar();

        if (c == '.' || c == '?' || c == '!' || c == '\n') {
            terminator = c;
            if ( c_prev != ' ' ) {
                iwordend[iword] = ichar;
                iword += 1;
            }
            break;
        } else {

            sentence[ichar] = c;

            if ( c_prev == ' ' && c != ' ' ) {
                iwordstart[iword] = ichar;
            }

            if ( c_prev != ' ' && c == ' ' ) {
                iwordend[iword] = ichar;
                iword += 1;
            }

            ichar += 1;
            c_prev = c;
        }

    }

    int nwords = iword;

    // reverse the order of the words
    printf("Words reversed  : ");
    for (int iword = nwords - 1; iword >= 0; iword--) {
        for (int ichar = iwordstart[iword]; ichar < iwordend[iword]; ichar++) {
            putchar(sentence[ichar]);
        }
        if (iword > 0) {
            putchar(' ');
        }
    }
    putchar(terminator);
    putchar('\n');

    return 0;

}
