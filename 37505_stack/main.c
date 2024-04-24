#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"



int main (void) {

    extern int nitems;
    extern int contents[];

    printf("Use single-digit integers to enter a reverse\n");
    printf("Polish notation expression, e.g.\n\n");
    printf("(q to quit) > 3 5 + =\n");
    printf("Value of expression = 8\n\n");

    while (true) {
        make_empty();
        printf("(q to quit) > ");
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
