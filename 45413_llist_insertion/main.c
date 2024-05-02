#include <stdio.h>
#include <stdlib.h>

struct node {
    int payload;
    struct node * next;
};

void llist_free (struct node *);
struct node * llist_insert (struct node *, struct node *);
struct node * llist_prepend (struct node *);
void llist_print (struct node *);
struct node * node_new (int);

void llist_free (struct node * llist) {
    while (llist != NULL) {
        struct node * next = llist->next;
        free(llist);
        llist = next;
    }
}

struct node * llist_insert (struct node * llist, struct node * new_node) {
    // assume list is ordered by payload
    if (llist == NULL) {
        return new_node;
    }
    struct node * curr = llist;
    struct node * prev = NULL;
    while (curr != NULL && curr->payload <= new_node->payload) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_node;
    new_node->next = curr;
    return llist;
}

struct node * llist_prepend (struct node * llist) {
    int n = 5;
    for (int i = 0; i < n; i++) {
        struct node * new = node_new((n - i - 1) * 10);
        new->next = llist;
        llist = new;
    }
    return llist;
}

void llist_print (struct node * llist) {
    struct node * p = llist;
    while (p != NULL) {
        if (p->next == NULL) {
            fprintf(stdout, "%p: { .payload = %d, .next = NULL }\n", (void *) p, p->payload);
        } else {
            fprintf(stdout, "%p: { .payload = %d, .next = %p }\n", (void *) p, p->payload, (void *) p->next);
        }
        p = p->next;
    }
}

struct node * node_new (int payload) {
    struct node * new = malloc(1 * sizeof(struct node));
    new->next = NULL;
    new->payload = payload;
    return new;
}

int main (void) {
    struct node * llist = NULL;
    struct node * new = NULL;

    llist = llist_prepend(llist);
    llist_print(llist);

    new = node_new(11);
    llist = llist_insert(llist, new);

    new = node_new(51);
    llist = llist_insert(llist, new);

    llist_print(llist);
    llist_free(llist);
    return EXIT_SUCCESS;
}
