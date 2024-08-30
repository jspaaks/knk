#ifndef WORD_H
#define WORD_H

#include <stdio.h>

typedef struct {
    char * buf;
    size_t cap;
    size_t ell;
} Word;

Word * word__fread_into_buffer (FILE * fp, char * filename, bool * eol);
void word__free (Word * word);

#endif
