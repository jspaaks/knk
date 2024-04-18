#include <stdio.h>
#include <stdbool.h>
#include "word.h"
#include "line.h"
#include "blank.h"


#define MAXWORDLENGTH 20
#define PAGEWIDTH 60

int main (void) {

    char word[MAXWORDLENGTH + 2] = { '\0' };
    char *word_0 = &word[0];
    char *word_n = &word[MAXWORDLENGTH + 1];

    char line[PAGEWIDTH + 1] = { '\0' };
    char *line_0 = &line[0];
    char *line_i = &line[0];
    char *line_n = &line[PAGEWIDTH];

    int n = 0;

    while (true) {
        n = read_next_word(&word[0], MAXWORDLENGTH);

        if (line_i + n > line_n) {
            printf("%s\n", line_0);
            blank(line_0, line_n);
            line_i = line_0;
        }
        add_word(line_i, word_0, n);
        blank(word_0, word_n);

        line_i += n;

        if (n == 0) {
            break;
        }
    }
    return 0;
}
