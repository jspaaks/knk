#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"



int main (void) {

    fprintf(stdout, "Use single-digit integers to enter a reverse-Polish\n");
    fprintf(stdout, "notation expression, e.g.\n\n");
    fprintf(stdout, "(q to quit) > 3 5 + =\n");
    fprintf(stdout, "     answer > 8\n");

    while (true) {
        make_empty();
        fprintf(stdout, "(q to quit) > ");
        while (true) {
            char c = getchar();
            if (c == ' ') {
                continue;
            } else if (c == 'q') {
                exit(EXIT_SUCCESS);
            } else if ('0' <= c && c <= '9') {
                if (push(c - '0') == false) {
                    fprintf(stderr, "Memory allocation failed. Aborting.\n");
                    exit(EXIT_FAILURE);
                }
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
                if (len() == 1) {
                    fprintf(stdout, "     answer > %d\n", (last())->payload);
                } else {
                    fprintf(stdout, "Stack is not scalar, aborting.\n");
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
                fprintf(stderr, "Invalid input, aborting.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}
