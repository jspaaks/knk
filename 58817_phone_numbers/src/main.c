#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char * filename;
    FILE * fp;
} File;

typedef struct phone_number {
    unsigned int area;
    unsigned int prefix;
    unsigned int line;
} PhoneNumber;

void print_phone_number (FILE * stream, char (*buf)[11]) {
    constexpr size_t narea = 3;
    constexpr size_t nprefix = 3;
    constexpr size_t nline = 4;
    char area[narea + 1] = {};
    char prefix[nprefix + 1] = {};
    char line[nline + 1] = {};
    char * p = &(*buf)[0];
    strncpy(area, p, narea);
    p += narea;
    strncpy(prefix, p, nprefix);
    p += nprefix;
    strncpy(line, p, nline);
    fprintf(stream, "(%s) %s-%s\n", area, prefix, line);
}

bool read_phone_number (File src, char (*buf)[11]) {
    // assume each line contains 10 digits
    size_t i = 0;
    size_t idigit = 0;
    const size_t ndigits = 10;
    int ch = '\0';
    bool errored = false;
    bool at_eof = false;
    bool at_eol = false;
    while (true) {
        ch = fgetc(src.fp);
        errored = ch == EOF && ferror(src.fp);
        at_eof = ch == EOF && feof(src.fp);
        at_eol = ch == '\n';

        if (errored) {
            fprintf(stderr, "Error reading from file '%s': %s.\n", src.filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        } else if (at_eof) {
            break;
        } else if (at_eol) {
            if (i == 0) {
                continue;
            }
            if (idigit != ndigits) {
                fprintf(stderr,
                        "Error reading phone number from file '%s': Unexpected number of digits collected (%zu).\n",
                        src.filename, idigit);
                exit(EXIT_FAILURE);
            }
            break;
        } else if (isdigit(ch)) {
            (*buf)[idigit] = ch;
            idigit++;
        }
        i++;
    }

    (*buf)[idigit] = '\0';

    return at_eof;
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: harmonize FILENAME\n"
                        "   Read US phone numbers in various formats from\n"
                        "   FILENAME and print them to STDOUT.\n");
        exit(EXIT_FAILURE);
    }

    File src = (File){
        .filename = argv[1],
        .fp = fopen(argv[1], "r"),
    };
    if (src.fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s", src.filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }

    bool eof = false;
    while (!eof) {
        char buf[11] = {};
        eof = read_phone_number(src, &buf);
        if (!eof) {
            print_phone_number(stdout, &buf);
        }
    }

    fclose(src.fp);

    return EXIT_SUCCESS;
}
