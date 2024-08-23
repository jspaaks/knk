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

    bool keep_going = true;
    int nrows = 0;
    int ncols = 10;
    fprintf(stdout, "Offset              Bytes              Characters\n");
    fprintf(stdout, "------  -----------------------------  ----------\n");
    while (keep_going) {
        fprintf(stdout, "%6d ", nrows * ncols);
        for (int icol = 0; icol < ncols; ++icol) {
            int ch = fgetc(fp0);
            if (ch == EOF && ferror(fp0)) {
                fprintf(stderr, "Error getting character from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (ch == EOF && feof(fp0)) {
                for (int i = icol; i < ncols; i++) {
                    fprintf(stdout, "   ");
                }
                break;
            }
            fprintf(stdout, " %02hx", ch);
        }
        fprintf(stdout, "  ");
        for (int icol = 0; icol < ncols; ++icol) {
            int ch = fgetc(fp1);
            if (ch == EOF && ferror(fp1)) {
                fprintf(stderr, "Error getting character from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            if (ch == EOF && feof(fp1)) {
                keep_going = false;
                break;
            }
            if (isprint(ch)) {
                fprintf(stdout, "%1c", (char) ch);
            } else {
                fprintf(stdout, "%1c", '.');
            }
        }
        fprintf(stdout, "\n");
        nrows++;
    }

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

