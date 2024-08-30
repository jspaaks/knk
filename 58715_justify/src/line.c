#include "line.h"
#include "word.h"
#include <assert.h>
#include <stdlib.h>

bool line__append (Line * line, Word * word, unsigned int ncols) {
    bool fits = line->nchars + line->nspans + word->cap <= ncols;
    if (fits) {
        line->words[line->nwords] = word;
        line->nchars += word->cap - 1;
        line->nwords++;
        line->nspans = line->nwords - 1;
    }
    return fits;
}

void line__free_and_reset (Line * line) {
    for (unsigned int i = 0; i < line->nwords; ++i) {
        word__free(line->words[i]);
        line->words[i] = nullptr;
    }
    line->nchars = 0;
    line->nspans = 0;
    line->nwords = 0;
}

void line__print (Line * line, FILE * fp, unsigned int ncols, bool justify) {

    const char SPACE_TYPE_1 = ' ';
    const char SPACE_TYPE_2 = ' ';
    const char SPACE_TYPE_3 = ' ';
    const char SPACE_TYPE_4 = ' ';

    if (line->nwords == 1) {
        int n = 0;
        fprintf(fp, "%s%n", line->words[0]->buf, &n);
        for (size_t i = 0; i < ncols - n; ++i) {
            fprintf(fp, "%c", SPACE_TYPE_1);
        }
        fprintf(fp, "%c", '\n');
        return;
    }

    assert(line->nspans > 0 && "linespans = 0\n");

    unsigned int spanwidth = (ncols - line->nchars) / line->nspans; // integer division
    unsigned int nremaining = ncols - line->nchars - line->nspans * spanwidth;

    float r;
    float chance;
    unsigned int i = 0;
    for (; i < line->nspans; ++i) {
        fprintf(fp, "%s", line->words[i]->buf);
        if (justify) {
            for (unsigned int j = 0; j < spanwidth; ++j) {
                fprintf(fp, "%c", SPACE_TYPE_2);
            }
            chance = ((float) nremaining) / (line->nspans - i);
            r = ((float) rand()) / RAND_MAX;
            if (r < chance) {
                fprintf(fp, "%c", SPACE_TYPE_3);
                nremaining--;
            }
        } else {
            fprintf(fp, "%c", SPACE_TYPE_4);
        }
    }
    fprintf(fp, "%s\n", line->words[i]->buf);
}
