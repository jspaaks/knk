#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define STACKSIZE 100


// EXTERNAL VARIABLES
int contents[STACKSIZE];
int nitems = 0;

bool is_empty (void);
bool is_full (void);
void make_empty (void);
int pop (void);
void push (int i);
void print (void);


bool is_empty (void) {

    return nitems == 0;

}


bool is_full (void) {

    return nitems == STACKSIZE;

}


int main (void) {

    int tmp;

    print();

    push(3);
    print();

    push(546);
    print();

    tmp = pop();
    print();

    tmp = pop();
    print();

    push(tmp);
    print();

    return 0;

}


void make_empty (void) {

    nitems = 0;

}


int pop (void) {

    if ( is_empty() ) {
        printf("stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        int r = contents[nitems - 1];
        nitems -= 1;
        return r;
    }

}


void push (int i) {

    if ( is_full() ) {
        printf("stack overflow\n");
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
