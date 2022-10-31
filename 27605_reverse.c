#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 1000

int main (void) {
    char sentence[MAXLENGTH];
    char *wordstarts[MAXLENGTH];
    char *wordends[MAXLENGTH];
    char *c = &sentence[0];
    char **wordstarts_i = &wordstarts[0];
    char **wordends_i = &wordends[0];
    char terminator;
    char c_prev = ' ';
    int iword = 0;

    // prompt the user for input
    printf("Enter a sentence: ");

    for (int ichar = 0; ichar < MAXLENGTH; ichar++) {
        // read the sentence into an array
        *c = getchar();
        if (*c == '.' || *c == '?' || *c == '!' || *c == '\n') {
            terminator = *c;
            *wordends_i = c;
            wordends_i++;
            break;
        }
        if ( c_prev == ' ' && *c != ' ' ) {
            *wordstarts_i = c;
            wordstarts_i++;
        }
        if ( c_prev != ' ' && *c == ' ' ) {
            *wordends_i = c;
            wordends_i++;
            iword++;
        }
        c_prev = *c;
        c++;
    }
    wordstarts_i--;
    wordends_i--;

    // reverse the order of the words
    printf("Words reversed  : ");
    for (; iword >= 0; iword--) {
        for (char *c = *wordstarts_i; c < *wordends_i; c++) {
            putchar(*c);
        }
        if (iword > 0) {
            putchar(' ');
        }
        wordstarts_i--;
        wordends_i--;
    }
    putchar(terminator);
    putchar('\n');

    return 0;
}
