#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum token {
    CHARACTERS = 0,
    WORDS,
    LINES,
} Token;

typedef unsigned int (*CountingFunction)(FILE *);

static unsigned int count_characters (FILE *);
static unsigned int count_lines (FILE *);
static unsigned int count_words (FILE *);
static Token determine_token (char *);
static void print_usage (void);

static unsigned int count_characters (FILE * fp) {
    unsigned int nchars = 0;
    while (true) {
        int ch = fgetc(fp);
        if (ch == EOF && ferror(fp)) {
            fprintf(stderr, "Error reading a character: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(fp)) {
            break;
        }
        nchars++;
    }
    return nchars;
}

static unsigned int count_lines (FILE * fp) {
    unsigned int nlines = 0;
    while (true) {
        int ch = fgetc(fp);
        if (ch == EOF && ferror(fp)) {
            fprintf(stderr, "Error reading a character: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(fp)) {
            break;
        }
        if (ch == '\n') {
            nlines++;
        }
    }
    return nlines;
}

static unsigned int count_words (FILE * fp) {
    unsigned int nwords = 0;
    int prev = ' ';
    while (true) {
        int ch = fgetc(fp);
        if (ch == EOF && ferror(fp)) {
            fprintf(stderr, "Error reading a character: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(fp)) {
            break;
        }
        if (isspace(prev) && !isspace(ch)) {
            nwords++;
        }
        prev = ch;
    }
    return nwords;
}

static Token determine_token (char * arg) {
    {
        bool cond1 = (strlen(arg) == 7) && (strncmp(arg, "--words", 7) == 0);
        bool cond2 = (strlen(arg) == 2) && (strncmp(arg, "-w", 2) == 0);
        if (cond1 || cond2) return WORDS;
    }
    {
        bool cond1 = (strlen(arg) == 7) && (strncmp(arg, "--lines", 7) == 0);
        bool cond2 = (strlen(arg) == 2) && (strncmp(arg, "-l", 2) == 0);
        if (cond1 || cond2) return LINES;
    }
    {
        bool cond1 = (strlen(arg) == 12) && (strncmp(arg, "--characters", 12) == 0);
        bool cond2 = (strlen(arg) == 2) && (strncmp(arg, "-c", 2) == 0);
        if (cond1 || cond2) return CHARACTERS;
    }
    print_usage();
    exit(EXIT_FAILURE);
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    Token token = determine_token(argv[1]);
    char * filename = argv[2];

    FILE * fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    CountingFunction functions[3] = {
        count_characters,
        count_words,
        count_lines,
    };

    unsigned int n = functions[token](fp);
    fprintf(stdout, "%d\n", n);

    fclose(fp);

    return EXIT_SUCCESS;
}

static void print_usage (void) {
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "   count [ -w | --words ] FILENAME\n");
    fprintf(stderr, "   count [ -l | --lines ] FILENAME\n");
    fprintf(stderr, "   count [ -c | --characters ] FILENAME\n");
    fprintf(stderr, "Count the number of words, lines, or characters in file FILENAME, respectively.\n");
}
