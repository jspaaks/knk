#include <stdio.h>
#include <stdbool.h>
#include "buffer.h"

#define NCHARSMAX 20

int buffer[NCHARSMAX+1] = {'\0'};
int *writepos = &buffer[0];
int *first = &buffer[0];
int *last = &buffer[NCHARSMAX - 1];

void print_buffer(void) {
    for (int *p = first; p <= last; p++) {
        printf("%c", *p);
    }
    printf("\n");
}

void clear_buffer(void) {
    for (int *p = first; p <= last; p++) {
        *p = '\0';
    }
}

void reset_buffer(void) {
    writepos = first;
}

void update_buffer(int this) {
    *writepos = this;
    if (writepos < last) {
        writepos++;
    } else {
        print_buffer();
        clear_buffer();
        reset_buffer();
        writepos = first;
    }
}