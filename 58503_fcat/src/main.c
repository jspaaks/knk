#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

    if (argc == 1) {
        fprintf(stderr, "Usage: %s FILENAME1 [FILENAME2] [...]\n", argv[0]);
        fprintf(stderr, "Print the contents of FILENAME1, FILENAME2, ... to STDOUT.\n");
        exit(EXIT_FAILURE);
    }

    FILE * fp;

    for (int iarg = 1; iarg < argc; iarg++) {
        char * filename = argv[iarg];
        fp = fopen(filename, "r");
        if (fp == nullptr) {
            fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    }

    for (int iarg = 1; iarg < argc; iarg++) {
        char * filename = argv[iarg];
        fp = fopen(filename, "r");
        if (fp == nullptr) {
            fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        while (true) {
            int ch = fgetc(fp);

            if (ch == EOF && feof(fp)) {
                break;
            }

            if (ch == EOF && ferror(fp)) {
                fprintf(stderr, "Error getting character from '%s': %s\n.", filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }

            int status = fputc(ch, stdout);
            if (status == EOF) {
                fprintf(stderr, "Error when writing a character to STDOUT: %s.\n", strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
        }
        fclose(fp);
    }
    return EXIT_SUCCESS;
}
