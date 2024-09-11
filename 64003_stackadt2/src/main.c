#include "stackadt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Program to demonstate features of the stackADT library.\n");

    constexpr size_t cap = 3;
    Stack s = create(cap);
    fprintf(stdout, " -- Created stack of capacity %zu.\n", cap);

    fprintf(stdout, " -- Testing if the stack is empty...\n");
    if (is_empty(s)) {
        fprintf(stdout, " -- Stack is empty.\n");
    } else {
        fprintf(stdout, " -- Stack is not empty.\n");
    }

    fprintf(stdout, " -- Pushing '(Item) 10' onto the stack.\n");
    push(s, 10);

    fprintf(stdout, " -- Testing if the stack is empty...\n");
    if (is_empty(s)) {
        fprintf(stdout, " -- Stack is empty.\n");
    } else {
        fprintf(stdout, " -- Stack is not empty.\n");
    }

    fprintf(stdout, " -- Pushing '(Item) 11' onto the stack.\n");
    push(s, 11);

    fprintf(stdout, " -- Testing if the stack is full...\n");
    if (is_full(s)) {
        fprintf(stdout, " -- Stack is full.\n");
    } else {
        fprintf(stdout, " -- Stack is not full.\n");
    }

    fprintf(stdout, " -- Pushing '(Item) 12' onto the stack.\n");
    push(s, 12);

    fprintf(stdout, " -- Testing if the stack is full...\n");
    if (is_full(s)) {
        fprintf(stdout, " -- Stack is full.\n");
    } else {
        fprintf(stdout, " -- Stack is not full.\n");
    }

    fprintf(stdout, " -- Popping the last item of the stack...\n");
    Item popped;
    popped = pop(s);
    fprintf(stdout, " -- Popped item was: %d\n", (int) popped);

    fprintf(stdout, " -- Testing if the stack is full...\n");
    if (is_full(s)) {
        fprintf(stdout, " -- Stack is full.\n");
    } else {
        fprintf(stdout, " -- Stack is not full.\n");
    }

    fprintf(stdout, " -- Popping the last item of the stack...\n");
    popped = pop(s);
    fprintf(stdout, " -- Popped item was: %d\n", (int) popped);

    fprintf(stdout, " -- Popping the last item of the stack...\n");
    popped = pop(s);
    fprintf(stdout, " -- Popped item was: %d\n", (int) popped);

    fprintf(stdout, " -- Testing if the stack is empty...\n");
    if (is_empty(s)) {
        fprintf(stdout, " -- Stack is empty.\n");
    } else {
        fprintf(stdout, " -- Stack is not empty.\n");
    }

    destroy(s);
    fprintf(stdout, " -- Freed memory resources previously held by Stack instance.\n");

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "    Demo usage of stackadt library.\n",
            exename);
}
