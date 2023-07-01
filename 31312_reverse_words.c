#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define NWORDS 30
#define NCHARS 21

int read_input(char words[NWORDS][NCHARS]) {
    int iword = -1;
    int ichar = -1;
    int c = '\n';
    int c_prev;
    while (true) {
        c_prev = c;
        c = getchar();
        if (c == '\n') {
            break;
        }
        if (!isalpha(c_prev) && isalpha(c)) {
            iword++;
            ichar = 0;
            if (iword >= NWORDS) {
                printf("Too many words to fit in allocated memory.\n");
                return 0;
            }
        }
        if (isalpha(c)) {
            words[iword][ichar] = c;
            ichar++;
            if (ichar >= NCHARS) {
                printf("Too many characters to fit in allocated memory.\n");
                return 0;
            }
        }
    }
    return iword;
}


int main (void) {
    printf("Enter a sentence: ");
    char words[NWORDS][NCHARS] = {""};
    int nwords = read_input(words);
    if (nwords > 0) {
        for (int i = nwords; i > 0; i--) {
            printf("%s ", words[i]);
        }
        printf("%s\n", words[0]);
        return EXIT_SUCCESS;
    }
    printf("No input read.\n");
    return EXIT_FAILURE;
}
