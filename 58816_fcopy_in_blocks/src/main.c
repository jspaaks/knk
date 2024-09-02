#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    FILE * fp;
    char * filename;
} File;

int main (int argc, char * argv[]) {

    if (argc != 3) {
        fprintf(stderr, "usage fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    File src = {
        .filename = argv[1],
        .fp = fopen(argv[1], "rb"),
    };
    if (src.fp == nullptr) {
        fprintf(stderr, "Can't open file '%s': %s.\n", src.filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    File dst = {
        .filename = argv[2],
        .fp = fopen(argv[2], "wb"),
    };
    if (dst.fp == nullptr) {
        fprintf(stderr, "Can't open file '%s': %s.\n", dst.filename, strerror(errno));
        fclose(src.fp);
        exit(EXIT_FAILURE);
    }

    constexpr unsigned int bsize = 512;
    unsigned char buf[bsize];
    unsigned int nread;
    unsigned int nwritten;

    while (true) {
        nread = fread(buf, 1, bsize, src.fp);
        if (nread < bsize && ferror(src.fp)) {
            fprintf(stderr, "Error reading from file '%s': %s.\n", src.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread < bsize && feof(src.fp)) {
            nwritten = fwrite(buf, 1, nread, dst.fp);
            if (nwritten < nread && ferror(dst.fp)) {
                fprintf(stderr, "Error writing to file '%s': %s.\n", dst.filename, strerror(errno));
                errno = 0;
                exit(EXIT_FAILURE);
            }
            break;
        }
        fwrite(buf, 1, bsize, dst.fp);
    }

    fclose(src.fp);
    fclose(dst.fp);

    return EXIT_SUCCESS;
}
