#include "word.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Word * word__create (size_t nbufcap);

static Word * word__create (size_t nbufcap) {
    size_t nbufcapmax = 18;
    if (nbufcap > nbufcapmax) {
        fprintf(stderr,
                " -- Requested buffer size exceeds maximum allowed value"
                " of %zu, words may appear split.\n",
                nbufcapmax);
        nbufcap = nbufcapmax;
    }
    char * buf = malloc(sizeof(char) * nbufcap);
    if (buf == nullptr) {
        fprintf(stderr, " -- Error allocating memory for word buffer.\n");
        exit(EXIT_FAILURE);
    }
    Word * word = malloc(sizeof(Word) * 1);
    if (buf == nullptr) {
        fprintf(stderr, " -- Error allocating memory for Word.\n");
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
                fprintf(stderr, " -- Error reading data from file '%s': %s.\n", filename, strerror(errno));
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
    Word * word = word__create((size_t) cursor1 - cursor0 + 1);
    {
        size_t i = 0;
        int ch;
        bool errored;
        while (i < word->cap - 1) {
            ch = fgetc(fp);
            *eof = ch == EOF && feof(fp);
            errored = ch == EOF && ferror(fp);
            if (errored) {
                fprintf(stderr, " -- Error reading data from file '%s': %s.\n", filename, strerror(errno));
                errno = 0;
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (*eof) {
                break;
            }
            word->buf[i] = ch;
            i++;
        }
        word->buf[i] = '\0';
    }
    return word;
}

void word__free (Word * word) {
    free(word->buf);
    free(word);
}
