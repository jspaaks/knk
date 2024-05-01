#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"


void print (char *);

struct node * contents = NULL;


bool is_empty (void) {
    return contents == NULL;
}


struct node * last (void) {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty, can't retrieve last node.\n");
        exit(EXIT_FAILURE);
    }
    struct node * p = contents;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}


int len (void) {
    int i = 0;
    struct node * p = contents;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}


void make_empty (void) {
    struct node * p = contents;
    while (p != NULL) {
        struct node * next = p->next;
        free(p);
        p = next;
    }
    contents = NULL;
}


int pop (void) {
    if ( is_empty() ) {
        printf("Not enough operands in expression, aborting.\n");
        exit(EXIT_FAILURE);
    }
    struct node * prev = NULL;
    struct node * curr = contents;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        contents = NULL;
    } else {
        prev->next = NULL;
    }
    int payload = curr->payload;
    free(curr);
    return payload;
}


bool push (int i) {
    // make the new node
    struct node * n = malloc(1 * sizeof(struct node));
    if (n == NULL) {
        return false;
    }
    n->payload = i;
    n->next = NULL;
    // insert the new node at the end of the llist
    if (is_empty()) {
        contents = n;
        return true;
    }
    struct node * p = contents;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = n;
    return true;
}


void print (char * src) {
    struct node * p = contents;
    printf("after %s() [\n", src);
    while (p != NULL) {
        if (p->next == NULL) {
            printf("  %p: { .payload = %d, .next = NULL },\n", (void *) p, p->payload);
        } else {
            printf("  %p: { .payload = %d, .next = %p },\n", (void *) p, p->payload, (void *) p->next);
        }
        p = p->next;
    }
    printf("]\n\n");
}
