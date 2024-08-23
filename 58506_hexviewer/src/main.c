#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        fprintf(stderr, "View the contents of file FILENAME as hexadecimal.\n");
        exit(EXIT_FAILURE);
    }

    char * filename = argv[1];

    FILE * fp0 = fopen(filename, "rb");
    if (fp0 == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    FILE * fp1 = fopen(filename, "rb");
    if (fp1 == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    int nread = 0;
    int ncols = 10 * 2;
    fprintf(stdout, "Offset              Bytes              Characters\n");
    fprintf(stdout, "------  -----------------------------  ----------\n");
    while (true) {
        if (nread % ncols == 0) {
            fprintf(stdout, "%6d ", nread / 2);
        }

        // ------------------
        if ((nread % ncols) < (ncols / 2)) {
            int ch = fgetc(fp0);
            if (ch == EOF && ferror(fp0)) {
                fprintf(stderr, "Error getting character from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (ch == EOF && feof(fp0)) {
                break;
            }
            fprintf(stdout, " %02hx", ch);
            nread++;
            if ((nread % ncols) == (ncols / 2)) {
                fprintf(stdout, "  ");
            }
        } else {
            int ch = fgetc(fp1);
            if (ch == EOF && ferror(fp1)) {
                fprintf(stderr, "Error getting character from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (ch == EOF && feof(fp1)) {
                break;
            }
            if (isprint(ch)) {
                fprintf(stdout, "%1c", (char) ch);
            } else {
                fprintf(stdout, "%1c", '.');
            }
            nread++;
        }

        // ------------------

        if (nread % ncols == 0) {
            fprintf(stdout, "\n");
        }
    }
    fprintf(stdout, "\n");

    int status0 = fclose(fp0);
    if (status0 == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    int status1 = fclose(fp1);
    if (status1 == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

