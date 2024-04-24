#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "word.h"
#include "blank.h"


char simplify_whitespace(char c) {
    return isspace(c) ? ' ' : c;
}


int read_next_word (char * line_i, char * const line_n, char * const word_0, char * const word_n, bool * const flush) {
    char c = '?';
    char * word_i = word_0;
    int n = 0;
    int state = -1;

    while (true) {

        state = ((word_i > word_n - 1) << 1) + ((line_i > line_n) << 0);
        if (state == 3) {
            // can't store new characters anywhere
            *flush = true;
            break;
        } 

        c = simplify_whitespace((char) getchar());
        //printf("%c s%d w%ld l%ld\n", c, state, word_n - word_i, line_n - line_i);

        if (c == EOF) {
            //*flush = true;
            break;
        }

        if (c == ' ') {
            if (word_i == word_0) {
                continue;
            } else {
                break;
            }
        }

        if (state == 0) {
            // neither word nor line is full
            *line_i = c;
            *word_i = c;
            n++;
            line_i++;
            word_i++;
        } else if (state == 1) {
            // line is full
            *word_i = c;
            n++;
            *flush = true;
            break;
        } else if (state == 2) {
            *word_n = '*';
            *line_i = '*';
            n = word_n - word_0 + 1;
        } else {
            printf("error: should not happen.");
        }
    }
    return n;
}
