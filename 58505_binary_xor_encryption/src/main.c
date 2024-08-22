#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * safeopen (char * filename, bool enable_writing) {
    FILE * fp = fopen(filename, enable_writing ? "wb" : "rb");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    return fp;
}

void safeclose (FILE * fp) {
    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, "Error closing file: %s", strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
}

int main (int argc, char * argv[]) {

    if (argc != 4) {
        fprintf(stderr, "Usage: %s FILENAME_PLAIN FILENAME_CYPHER KEY\n", argv[0]);
        fprintf(stderr,
                "Encrypt the contents of FILENAME_PLAIN using character KEY, and\nstore it in file FILENAME_CYPHER.\n");
        exit(EXIT_FAILURE);
    }
    char * plain = argv[1];
    FILE * fp_plain = safeopen(plain, false);

    char * cypher = argv[2];
    FILE * fp_cypher = safeopen(cypher, true);

    if (strlen(argv[3]) != 1) {
        fprintf(stderr, "KEY should be a single character.\n");
        exit(EXIT_FAILURE);
    }
    char key = *argv[3];

    while (true) {
        int ch = fgetc(fp_plain);
        if (ch == EOF && ferror(fp_plain)) {
            fprintf(stderr, "Error getting character from file '%s': %s.\n", plain, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (ch == EOF && feof(fp_plain)) {
            break;
        }
        int status = fputc(ch ^ key, fp_cypher);
        if (status == EOF) {
            fprintf(stderr, "Error writing character to file '%s': %s.\n", cypher, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
    }

    safeclose(fp_plain);
    safeclose(fp_cypher);
    return EXIT_SUCCESS;
}
