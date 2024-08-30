#include "line.h"
#include "word.h"

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

void line__print (Line * line, FILE * fp, unsigned int ncols) {
    unsigned int spanwidth = (ncols - line->nchars) / line->nspans; // integer division
    unsigned int nremaining = ncols - line->nchars - line->nspans * spanwidth;
    for (unsigned int i = 0; i < line->nwords; ++i) {
        fprintf(fp, "%s", line->words[i]->buf);
        for (unsigned int j = 0; j < spanwidth; ++j) {
            if (i < line->nwords - 1) {
                fprintf(fp, "%c",  ' ');
            }
        }
    }
    for (unsigned int i = 0; i < nremaining; ++i) {
        fprintf(fp, "%c", '=');
    }
    fprintf(fp, "\n");
}
