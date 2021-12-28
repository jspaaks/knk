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

    while (true) {

        make_empty();

        printf("Enter a reverse Polish notation expression (q to quit): ");

        while (true) {

            char c = getchar();

            if (c == ' ') {

                continue;

            } else if (c == 'q') {

                exit(EXIT_SUCCESS);

            } else if ('0' <= c && c <= '9') {

                push(c - '0');

            } else if (c == '*') {

                int b = pop();
                int a = pop();
                push(a * b);

            } else if (c == '/') {

                int b = pop();
                int a = pop();
                push(a / b);

            } else if (c == '+') {

                int b = pop();
                int a = pop();
                push(a + b);

            } else if (c == '=') {

                if (nitems == 1) {
                    printf("Value of expression: %d\n", contents[nitems - 1]);
                } else {
                    printf("Stack is not scalar, aborting.\n");
                    exit(EXIT_FAILURE);
                }

                // gobble up remaining characters
                while (getchar() != '\n') {
                    continue;
                }

                break;

            } else if (c == '-') {

                int b = pop();
                int a = pop();
                push(a - b);

            } else if (c == '\n') {

                break;

            } else {
                printf("Invalid input, aborting.\n");
                exit(EXIT_FAILURE);
            }

        }

    }

    return 0;

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
