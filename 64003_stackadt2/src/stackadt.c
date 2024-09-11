#include "stackadt.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct stack_type {
    Item * contents;
    int top;
    int size;
};

Stack create (int size) {
    Stack s = malloc(sizeof(struct stack_type));
    assert(s != nullptr && "Error in create: stack could not be created.");
    s->contents = malloc(size * sizeof(Item));
    if (s->contents == nullptr) {
        free(s);
        fprintf(stderr, "Error in create: stack could not be created.");
        exit(EXIT_FAILURE);
    }
    s->top = 0;
    s->size = size;
    return s;
}

void destroy (Stack s) {
    free(s->contents);
    free(s);
}

void make_empty (Stack s) {
    s->top = 0;
}

bool is_empty (Stack s) {
    return s->top == 0;
}

bool is_full (Stack s) {
    return s->top == s->size;
}

void push (Stack s, Item i) {
    assert(!is_full(s) && "Error in push: stack is full.");
    s->contents[s->top] = i;
    s->top++;
}

Item pop (Stack s) {
    assert(!is_empty(s) && "Error in pop: stack is empty.");
    s->top--;
    return s->contents[s->top];
}
