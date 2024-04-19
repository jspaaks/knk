#include "blank.h"


void blank (char * const first, char * const last) {
    char * pos = first;
    while (pos <= last) {
        *pos = '\0';
        pos++;
    }
}
