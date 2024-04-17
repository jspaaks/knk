#include <stdio.h>
#include <stdbool.h>
#include "word.h"

#define MAXWORDLENGTH 20
char word[MAXWORDLENGTH + 2] = { '\0' };


int main (void) {
    int n = 0;
    while (true) {
        n = read_next_word(&word[0], MAXWORDLENGTH);
        if (n == 0) {
            break;
        }
        printf("%-21s: %2d\n", word, n);
        reset_word(&word[0], MAXWORDLENGTH);
    }
    return 0;
}
