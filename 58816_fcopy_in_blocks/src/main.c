#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {

    FILE * source_fp;
    FILE * dest_fp;

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

    constexpr unsigned int bsize = 512;
    unsigned char buf[bsize];
    unsigned int nread;
    unsigned int nwritten;

    while (true) {
        nread = fread(buf, 1, bsize, source_fp);
        if (nread < bsize && ferror(source_fp)) {
            fprintf(stderr, "Error reading from file '%s': %s", argv[1], strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread < bsize && feof(source_fp)) {
            nwritten = fwrite(buf, 1, nread, dest_fp);
            if (nwritten < nread && ferror(dest_fp)) {
                fprintf(stderr, "Error writing to file '%s': %s", argv[2], strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            break;
        }
        fwrite(buf, 1, bsize, dest_fp);
    }

    fclose(source_fp);
    fclose(dest_fp);

    return EXIT_SUCCESS;
}
