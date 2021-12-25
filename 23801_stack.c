#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define STACKSIZE 100


// EXTERNAL VARIABLES
char stack[STACKSIZE];
int nitems = 0;

bool is_empty (void);
bool is_full (void);
void make_empty (void);
char pop (void);
void push (char c);
void print (void);


bool is_empty (void) {

    return nitems == 0;

}


bool is_full (void) {

    return nitems == STACKSIZE;

}


int main (void) {

    printf("Enter a series of parentheses and/or braces: ");

    while (true) {

        char c = getchar();

        if (c == '\n') {

            if (nitems == 0) {
                printf("Parentheses/braces are nested properly.\n");
                exit(EXIT_SUCCESS);
            } else {
                printf("Parentheses/braces are improperly nested.\n");
                exit(EXIT_FAILURE);
            }

        } else if (c == '{' || c == '(') {

            push(c);

        } else if (c == '}') {

            char popped = pop();

            if (popped != '{') {
                printf("Parentheses/braces are improperly nested.\n");
                exit(EXIT_FAILURE);
            }

        } else if (c == ')') {

            char popped = pop();

            if (popped != '(') {
                printf("Parentheses/braces are improperly nested.\n");
                exit(EXIT_FAILURE);
            }

        }
    }

    return 0;

}


void make_empty (void) {

    nitems = 0;

}


char pop (void) {

    if ( is_empty() ) {
        printf("stack underflow\n");
        exit(EXIT_FAILURE);
    } else {
        char c = stack[nitems - 1];
        nitems -= 1;
        return c;
    }

}


void push (char c) {

    if ( is_full() ) {
        printf("stack overflow\n");
        exit(EXIT_FAILURE);
    } else {
        stack[nitems] = c;
        nitems += 1;
    }

}


void print (void) {

    printf("[");
    for (int i = 0; i < nitems; i++) {
        printf("'%c'", stack[i]);
        if (i < nitems - 1 ) {
            printf(", ");
        }
    }
    printf("]\n");

}
