#include <stdio.h>
#include <stdlib.h>

struct node {
    int payload;
    struct node * next;
};

void llist_delete (struct node **, int);
void llist_free (struct node *);
struct node * llist_prepend (struct node *);
void llist_print (struct node *);
struct node * node_new (int);

void llist_delete (struct node ** llist, int payload) {
    if (llist == NULL) {
        // llist empty, won't be able to find a match
        return;
    }
    struct node * prev = NULL;
    struct node * curr = *llist;
    while (curr != NULL && curr->payload != payload) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        // no matches
        return;
    }
    if (prev == NULL) {
        // match found at beginning
        *llist = (*llist)->next;
    } else {
        // match found at index > 0
        prev->next = curr->next;
    }
    free(curr);
    return;
}

void llist_free (struct node * llist) {
    while (llist != NULL) {
        struct node * next = llist->next;
        free(llist);
        llist = next;
    }
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

    llist = llist_prepend(llist);
    llist_print(llist);

    llist_delete(&llist, 0);

    llist_print(llist);
    llist_free(llist);
    return EXIT_SUCCESS;
}
