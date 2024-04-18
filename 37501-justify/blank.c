#include "blank.h"


void blank (char *first, char *last) {
    char *pos = first;
    while (pos <= last) {
        *pos = '\0';
        pos++;
    }
}
