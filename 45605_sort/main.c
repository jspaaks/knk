#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN_MAX 20

int comparator (const void *, const void *);
char * create_word (void);
void destroy_word (char *);
int read_word (char *);

char * create_word (void) {
    char * word = malloc((WORD_LEN_MAX + 1) * sizeof(char));
    if (word == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for new word.\n");
    }
    return word;
}

void destroy_word (char * word) {
    free(word);
}

int main (void) {
    int nwords = 0;
    int nwords_max = 1;
    int nchars = -1;
    char * word = NULL;
    char ** words = malloc(nwords_max * sizeof(char *));
    if (words == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for array of char pointers 'words'.\n");
    }
    while (true) {
        fprintf(stdout, "Enter word: ");
        word = create_word();
        nchars = read_word(word);
        if (nchars == 0) {
            break;
        }
        words[nwords] = word;
        nwords++;
        if (nwords >= nwords_max) {
            nwords_max *= 2;
            words = realloc(words, nwords_max * sizeof(char *));
            if (words == NULL) {
                fprintf(stderr, "Something went wrong reallocating memory for array of char pointers 'words'.\n");
            }
        }
    }
    qsort(words, nwords, sizeof(char *), comparator);
    for (int i = 0; i < nwords; i++) {
        fprintf(stdout, "%s\n", words[i]);
    }
    for (int i = 0; i < nwords; i++) {
        destroy_word(words[i]);
    }
    free(words);
    exit(EXIT_SUCCESS);
}

int read_word (char * word) {
    int nchars = 0;
    while (true) {
        int ch = getchar();
        if (ch == '\n') {
            *word = '\0';
            break;
        }
        if (nchars < WORD_LEN_MAX) {
            *word = (char) ch;
            nchars++;
            word++;
        }
    }
    return nchars;
}

int comparator (const void * p, const void * q) {
    const char * pp = *(const char **) p;
    const char * qq = *(const char **) q;
    int cmp = strcmp(pp, qq);
    if (cmp < 0) {
        return -1;
    } else if (cmp == 0) {
        return 0;
    } else {
        return 1;
    }
}