#include "word.h"
#include <stdio.h>

int read_char (void) {
    int ch = getchar();
    return ch == '\n' || ch == '\t' ? ' ' : ch;
}

void read_word (char * word, int len) {
    int ch;
    int pos = 0;
    while ((ch = read_char()) == ' ') {
        ;
    }
    while (ch != ' ' && ch != EOF) {
        if (pos < len) {
            word[pos] = ch;
            pos++;
        }
        ch = read_char();
    }
    word[pos] = '\0';
}
