#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"


#define STACKSIZE 100


int contents[STACKSIZE];
int nitems = 0;


bool is_empty (void) {
    return nitems == 0;
}


bool is_full (void) {
    return nitems == STACKSIZE;
}


void make_empty (void) {
    nitems = 0;
}


int pop (void) {
    if ( is_empty() ) {
        printf("Not enough operands in expression, aborting.\n");
        exit(EXIT_FAILURE);
    } else {
        int r = contents[nitems - 1];
        nitems -= 1;
        return r;
    }
}


void push (int i) {
    if ( is_full() ) {
        printf("Expression too complex, aborting.\n");
        exit(EXIT_FAILURE);
    } else {
        contents[nitems] = i;
        nitems += 1;
    }
}


void print (void) {
    printf("[");
    for (int i = 0; i < nitems; i++) {
        printf("%d", contents[i]);
        if (i < nitems - 1 ) {
            printf(", ");
        }
    }
    printf("]\n");
}
