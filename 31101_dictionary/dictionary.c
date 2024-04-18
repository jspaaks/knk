#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N_LETTERS_MAX 20
#define N_WORDS_MAX 10

void print_words(char *, int, char *, char *);
int read_input(char *);

int main (void) {
    char words[N_WORDS_MAX * (N_LETTERS_MAX + 1)];
    char *p = words;
    char *smallest = words;
    char *largest = words;
    int nwords = 0;
    while (nwords < N_WORDS_MAX) {
        int nchars = read_input(p);
        if (strcmp(p, smallest) < 0) {
            smallest = p;
        }
        if (strcmp(p, largest) > 0) {
            largest = p;
        }
        nwords++;
        if (nchars == 4) {
            break;
        }
        p = p + N_LETTERS_MAX + 1;
    }
    print_words(words, nwords, smallest, largest);
    return EXIT_SUCCESS;
}

int read_input(char *p) {
    printf("Enter word: ");
    int nchars = 0;
    while (nchars < N_LETTERS_MAX) {
        char ch = getchar();
        if (ch == '\n') {
            *p = '\0';
            break;
        } else {
            *p = ch;
        }
        nchars++;
        p++;
    }
    return nchars;
}

void print_words(char *words, int nwords, char *smallest, char *largest) {
    for (int iword = 0; iword < nwords; iword++) {
        char *p = &words[iword * (N_LETTERS_MAX + 1)];
        char *str_smallest = (p == smallest) ? " (smallest)" : "";
        char *str_largest = (p == largest) ? " (largest)" : "";
        printf("%s%s%s\n", p, str_smallest, str_largest);
    }
    return;
}
