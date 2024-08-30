#include "word.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static Word * word__create (size_t nbufcap);

static Word * word__create (size_t nbufcap) {
    char * buf = malloc(sizeof(char) * nbufcap);
    if (buf == nullptr) {
        fprintf(stderr, "Error allocating memory for word buffer.\n");
        exit(EXIT_FAILURE);
    }
    Word * word = malloc(sizeof(Word) * 1);
    if (buf == nullptr) {
        fprintf(stderr, "Error allocating memory for Word.\n");
        exit(EXIT_FAILURE);
    }
    word->buf = buf;
    word->cap = nbufcap;
    return word;
}

Word * word__fread_into_buffer (FILE * fp, char * filename, bool * eof) {
    // -------------------------------------------------------------------------- //
    //  determine how much space we need for the next word from fp
    // -------------------------------------------------------------------------- //
    long cursor0;
    long cursor1;
    {
        int prev = ' ';
        int curr;
        bool word_starts;
        bool word_ends;
        bool errored;
        while (true) {
            curr = fgetc(fp);
            word_starts = isspace(prev) && !isspace(curr);
            word_ends = !isspace(prev) && isspace(curr);
            *eof = curr == EOF && feof(fp);
            errored = curr == EOF && ferror(fp);
            if (errored) {
                fprintf(stderr, "Error reading data from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (word_starts) {
                cursor0 = ftell(fp) - 1;
            }
            if (word_ends || *eof) {
                cursor1 = ftell(fp) - 1;
                break;
            }
            prev = curr;
        }
        fseek(fp, cursor0, SEEK_SET);
    }

    // -------------------------------------------------------------------------- //
    //  allocate a buffer of the exact size needed and fill it with data from fp
    // -------------------------------------------------------------------------- //
    long cap = cursor1 - cursor0 + 1;
    Word * word = word__create((size_t) cap);
    long i = 0;
    int ch;
    bool errored;
    for (; i < cap - 1; ++i) {
        ch = fgetc(fp);
        *eof = ch == EOF && feof(fp);
        errored = ch == EOF && ferror(fp);
        if (errored) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        if (*eof) {
            break;
        }
        word->buf[i] = ch;
    }
    word->buf[i] = '\0';
    return word;
}

void word__free(Word * word) {
    free(word->buf);
    free(word);
}
