#include <stdio.h>
#include <stdlib.h>

struct node {
    int payload;
    struct node * next;
};

int count (struct node *, int);
void inventory_free (struct node *);
struct node * prepend (struct node *, int);
void print (struct node *);

int count (struct node * p, int payload) {
    int n = 0;
    while (p != NULL) {
        p->payload == payload ? n++ : n;
        p = p->next;
    }
    return n;
}

void inventory_free (struct node * p) {
    while (p != NULL) {
        struct node * tmp = p;
        p = p->next;
        free(tmp);
    }
}

int main (void) {
    struct node * inventory = NULL;
    for (int i = 9; i >= 0; i--) {
        inventory = prepend(inventory, i % 4);
    }
    print(inventory);
    for (int i = 0; i < 3; i++) {
        fprintf(stdout, "%d occurs %d times.\n", i, count(&inventory[0], i));
    }
    inventory_free(&inventory[0]);
}

struct node * prepend (struct node * llist, int payload) {
    struct node * n = malloc(1 * sizeof(struct node));
    n->next = llist;
    n->payload = payload;
    return n;
}

void print (struct node * p) {
    while (p != NULL) {
        if (p->next == NULL) {
            fprintf(stdout, "%p: { .payload = %d, .next = NULL }\n", (void *) p, p->payload);
        } else {
            fprintf(stdout, "%p: { .payload = %d, .next = %p }\n", (void *) p, p->payload, (void *) p->next);
        }
        p = p->next;
    }
}
