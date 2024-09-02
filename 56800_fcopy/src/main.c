#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {

    FILE * source_fp;
    FILE * dest_fp;
    int ch;
    if (argc != 3) {
        fprintf(stderr, "usage fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    source_fp = fopen(argv[1], "rb");
    if (source_fp == nullptr) {
        fprintf(stderr, "Can't open file '%s'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");
    if (dest_fp == nullptr) {
        fprintf(stderr, "Can't open file '%s'.\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_fp)) != EOF) {
        putc(ch, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);

    return EXIT_SUCCESS;
}
