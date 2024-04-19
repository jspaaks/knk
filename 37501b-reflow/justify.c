#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "word.h"
#include "line.h"
#include "blank.h"


#define MAXWORDLENGTH 20  // including '*'
#define PAGEWIDTH 60

int main (void) {

    printf("\n\ndoesnt quite work\n\n");

    char word[MAXWORDLENGTH + 2] = { '\0' };
    char * const word_0 = &word[0];
    char * const word_n = &word[MAXWORDLENGTH - 1];

    char line[PAGEWIDTH + 1] = { '\0' };
    char * const line_0 = &line[0];
    char * const line_n = &line[PAGEWIDTH - 1];
    char * line_i = &line[0];

    int n = 0;
    bool flush = false;

    while (true) {
        n = read_next_word(line_i, line_n, word_0, word_n, &flush);
        if (flush || n == 0) {
            blank(line_i, line_n);
            printf("%s\n", line_0);
            blank(line_0, line_n);
            strncpy(line_0, word_0, n);
            line_i = line_0 + n;
            flush = false;
            if (n == 0) {
                break;
            }
        } else {
            line_i += n;
            if (line_i != line_0 && line_i < line_n) {
                *line_i = ' ';
                line_i++;
            }
        }
    }
    return 0;
}
