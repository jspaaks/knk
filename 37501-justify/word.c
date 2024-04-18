#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "word.h"


char simplify_whitespace(char c) {
    return isspace(c) ? ' ' : c;
}


int read_next_word (char word[], int n) {
    char c = '?';
    int i = 0;
    while (true) {
        c = simplify_whitespace((char) getchar());
        if (c == EOF) {
            return 0;
        } else if (c == ' ') {
            if (i == 0) {
                continue;
            } else {
                break;
            }
        } else {
            if (i < n) {
                word[i] = c;
            } else {
                word[n] = '*';
            }
            i++;
        }
    }
    return i > n ? n + 1 : i;
}
