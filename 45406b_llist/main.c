#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int payload;
    struct node * next;
};

struct node * delete_from_list (struct node *, int);
struct node * prepend (struct node * llist, int payload);
void print_llist (struct node * p);

struct node * delete_from_list (struct node * llist, int n) {
    struct node * cur = llist;
    struct node * prev = NULL;
    while (cur != NULL && cur->payload != n) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        // list was NULL or n not found
        return llist;
    }
    if (prev == NULL) {
        // list was not NULL and payload found at beginning of list
        llist = llist->next;
        free(cur);
    } else {
        // delete node at cur
        prev->next = cur->next;
        free(cur);
    }
    return llist;
}

int main (void) {
    struct node * llist;

    for (int i = 0; i < 4; i++) {
        llist = prepend(llist, i);
    }
    print_llist(llist);
    llist = delete_from_list(llist, 2);
    print_llist(llist);
}

void print_llist (struct node * p) {
    while (true) {
        if (p == NULL) {
            printf("Empty list\n");
            break;
        } else if ((*p).next == NULL) {
            printf("%p: { payload: %d, next: %s }\n", (void *) p, (*p).payload, "NULL");
            break;
        } else {
            printf("%p: { payload: %d, next: %p }\n", (void *) p, (*p).payload, (void *) (*p).next);
            p = (*p).next;
        }
    }
}

struct node * prepend (struct node * llist, int payload) {
    struct node * n = malloc(1 * sizeof(struct node *));
    (*n).next = llist;
    (*n).payload = payload;
    return n;
}
