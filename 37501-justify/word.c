#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


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
                i++;
            } else {
                word[i] = '*';
            }
        }
    }
    return i;
}


void reset_word (char word[], int n) {
    // clear the positions where letters are stored
    for (int i = 0; i < n; i++) {
        word[i] = '\0';
    }
    // clear the '*' position
    word[n] = '\0';
}