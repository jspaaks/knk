#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define NCHARS 1000

void reverse_name(char *fullname) {
    char reversed[NCHARS] = "";
    char *src = fullname;
    char *tgt = reversed;
    // eat leading spaces
    while (!isalpha(*src)) {
        src++;
    }
    char initial = toupper(*src);
    // eat the rest of the first name
    while (isalpha(*src)) {
        src++;
    }
    // eat whatever separates the first and last name
    while (!isalpha(*src)) {
        src++;
    }
    // copy the chars of the last name
    *tgt = toupper(*src);
    src++;
    tgt++;
    while (isalpha(*src)) {
        *tgt = *src;
        src++;
        tgt++;
    }
    char tmp[5] = "";
    sprintf(tmp, ", %c.", initial);
    strcpy(tgt, tmp);
    // overwrite input argument fullname with the reversed and abbreviated name
    strcpy(fullname, reversed);
}


int main (void) {
    printf("Enter a first and last name separated by a space: ");
    char name[NCHARS] = "";
    char *p = name;
    for (char c; (c = getchar()) != '\n'; p++) {
        *p = c;
    }
    reverse_name(name);
    printf("Reversed and abbreviated name is '%s'\n", name);
    return EXIT_SUCCESS;
}
