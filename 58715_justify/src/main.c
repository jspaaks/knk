#include "files.h"
#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <time.h>

void justify (Files *, unsigned int);

int main (int argc, char * argv[]) {

    srand(time(nullptr));

    if (argc != 7) {
        fprintf(stderr,
                "Usage: %s -i INPUT_FILENAME -o OUTPUT_FILENAME -c COLUMN\n"
                "    Read the text of INPUT_FILENAME, justify it to\n"
                "    character column COLUMN, then write the result to\n"
                "    OUTPUT_FILENAME.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    Files files = {};

    if (strncmp(argv[1], "-i", 3) != 0) {
        fprintf(stderr, " -- Unexpected argument '%s'.\n", argv[1]);
    }
    if (strncmp(argv[3], "-o", 3) != 0) {
        fprintf(stderr, " -- Unexpected argument '%s'.\n", argv[3]);
    }
    if (strncmp(argv[5], "-c", 3) != 0) {
        fprintf(stderr, " -- Unexpected argument '%s'.\n", argv[5]);
    }
    strncpy(files.read.filename, argv[2], FILENAME_MAX);
    strncpy(files.write.filename, argv[4], FILENAME_MAX);
    open_files(&files);

    unsigned int ncols;
    int nread = sscanf(argv[6], " %u", &ncols);
    if (nread != 1) {
        fprintf(stderr, " -- Error reading COLUMN argument.\n");
        close_files(&files);
        exit(EXIT_FAILURE);
    }

    justify(&files, ncols);

    close_files(&files);
    return EXIT_SUCCESS;
}

void justify (Files * files, unsigned int ncols) {
    Line line = {};
    bool eof = false;
    while (!eof) {
        Word * word = word__fread_into_buffer(files->read.fp, files->read.filename, &eof);
        bool fits = line__append(&line, word, ncols);
        if (!fits) {
            line__print(&line, files->write.fp, ncols);
            line__free_and_reset(&line);
            line__append(&line, word, ncols);
        }
    }
    // TODO deal with printing last line and/or last word
    line__free_and_reset(&line);
}
