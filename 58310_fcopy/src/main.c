#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {

    if (argc != 3) {
        char * p = argv[0];
        char * q = argv[0];
        while (*p != '\0') {
            if (*p == '/' || *p == '\\') {
                q = p;
            }
            p++;
        }
        fprintf(stderr, "Usage: %s SRC DST\n", ++q);
        fprintf(stderr, "Copy a file from SRC to DST.\n");
        exit(EXIT_FAILURE);
    }

    FILE * src = fopen(argv[1], "rb");
    if (src == NULL) {
        fprintf(stderr, "Could not open source file '%s'. Aborting.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE * dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        fprintf(stderr, "Could not open destination file '%s'. Aborting.\n", argv[2]);
        fclose(src);
        exit(EXIT_FAILURE);
    }

    while (true) {
        int ch = getc(src);
        if (ch == EOF) break;
        int n = putc(ch, dst);
        if (n == EOF) {
            // putc returns EOF in case of an error
            fprintf(stderr, "An error occurred while copying from '%s' to '%s'. Aborting.\n", argv[1], argv[2]);
        }
    }

    fclose(src);
    fclose(dst);

    return EXIT_SUCCESS;
}
