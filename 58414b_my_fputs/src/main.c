#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_fputs (const char * restrict s, FILE * restrict fp) {
    const char * p = s;
    while (*p != '\0') {
        int i = fputc(*p, fp);
        if (i == EOF) return EOF;
        p++;
    }
    return (int) (p - s);
}

char * read_stdin (size_t bufsize) {
    char * s = malloc(bufsize * 1);
    char * p = s;
    while ((size_t) (p - s) < bufsize) {
        int c = fgetc(stdin);
        if (c == EOF) {
            if (ferror(stdin)) {
                fprintf(stderr, "Error reading from STDIN. Aborting.\n%s\n", strerror(errno));
                exit(EXIT_FAILURE);
            } else if (feof(stdin)) {
                return s;
            }
        }
        *p = c;
        p++;
    }
    return s;
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s BUFSIZE FILENAME\n", argv[0]);
        fprintf(stderr, "Read at most BUFSIZE - 1 characters from STDIN and print it to file FILENAME.\n");
        exit(EXIT_FAILURE);
    }

    size_t bufsize;
    sscanf(argv[1], " %zu", &bufsize);

    fprintf(stdout, "BUFSIZE %zu requested.\n", bufsize);

    char * filename = argv[2];
    char * str = read_stdin(bufsize);

    FILE * fp = fopen(filename, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Something went wrong trying to open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    int i = my_fputs(str, fp);
    if (i == EOF) {
        fprintf(stderr, "Something went wrong writing string '%s' to file '%s': %s\n", str, filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Wrote %d characters from STDIN to file '%s'.\n", i, filename);

    free(str);

    return EXIT_SUCCESS;
}
