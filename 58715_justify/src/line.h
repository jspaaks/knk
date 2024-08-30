#ifndef LINE_H
#define LINE_H

#include "word.h"

typedef struct line {
    Word * words[100];
    unsigned int nchars;
    unsigned int nspans;
    unsigned int nwords;
} Line;


bool line__append (Line *, Word *, unsigned int);
void line__free_and_reset (Line *);
void line__print (Line *, FILE *, unsigned int);

#endif
