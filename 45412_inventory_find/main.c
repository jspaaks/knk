#include <stdio.h>
#include <stdlib.h>

struct node {
    int payload;
    struct node * next;
};

struct node * find_last (struct node *, int);
void inventory_free (struct node *);
struct node * prepend (struct node *, int);
void print (struct node *);

struct node * find_last (struct node * p, int payload) {
    struct node * q = NULL;
    while (p != NULL) {
        q = p->payload == payload ? p : q;
        p = p->next;
    }
    return q;
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
    for (int i = 0; i < 5; i++) {
        struct node * last = find_last(&inventory[0], i);
        if (last == NULL) {
            fprintf(stdout, "%d has no occurrences.\n", i);
        } else {
            fprintf(stdout, "The last occurrence of %d is at %p.\n", i, (void *) last);
        }
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
