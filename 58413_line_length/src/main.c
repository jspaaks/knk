#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_length (const char * filename, int iline) {

    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error occurred opening file %s: %s. Aborting.\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (iline < 0) return 0;

    for (int i = 0; i < iline; ++i) {
        while (true) {
            int ch = fgetc(fp);
            if (ch == EOF) return 0;
            if (ch == '\n') break;
        }
    }

    int n = 0;
    while (true) {
        int ch = fgetc(fp);
        if (ch == EOF) return 0;
        if (ch == '\n') break;
        n++;
    }
    return n;
}

int main (int argc, char * argv[]) {

    if (argc != 3) {
        fprintf(stdout, "Usage: line-length FILENAME LINENO\n");
        fprintf(stdout,
                "Return the line length of line LINENO in file FILENAME.\nNote: line numbers start counting at 0.\n");
        exit(EXIT_FAILURE);
    }
    int iline;
    sscanf(argv[2], " %d", &iline);
    int n = line_length(argv[1], iline);
    fprintf(stdout, "%d\n", n);
    return EXIT_SUCCESS;
}
