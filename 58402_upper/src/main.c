#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        fprintf(stderr, "Read from file FILENAME and print its contents in uppercase to STDOUT.\n");
        exit(EXIT_FAILURE);
    }
    char * filename = argv[1];

    FILE * fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    while (true) {
        int ch = fgetc(fp);
        if (ch == EOF && ferror(fp)) {
            fprintf(stderr, "Error getting character from file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        } else if (ch == EOF && feof(fp)) {
            break;
        } else if (isalpha(ch)) {
            ch = toupper(ch);
        } else {
            // pass
        }
        int status = fputc(ch, stdout);
        if (status == EOF) {
            fprintf(stderr, "Error printing a character to STDIN: %s.\n", strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }

    int status = fclose(fp);
    if (status != 0) {
        fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Done.\n");
    return EXIT_SUCCESS;
}
