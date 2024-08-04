#include "queue/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr size_t queue_name_length = 100;

typedef struct node {
    Item payload;
    struct node * next;
} Node;

struct queue {
    size_t nact;
    char name[queue_name_length];
    Node * elems;
};

Queue * queue__create (char * name) {
    Queue * q = malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Error allocating memory for new queue instance.\n");
        exit(EXIT_FAILURE);
    }
    q->elems = NULL;
    q->nact = 0;
    strncpy(q->name, name, queue_name_length - 1);
    return q;
}

void queue__destroy (Queue ** queue) {
    Queue ** tmp = queue;
    Item ignored;
    size_t nact = (*queue)->nact;
    for (size_t i = 0; i < nact; i++) {
        queue__pop(*queue, &ignored);
    }
    free(*tmp);
    *tmp = NULL;
}

size_t queue__get_length (const Queue * queue) {
    return queue->nact;
}

bool queue__isempty (const Queue * queue) {
    return queue->nact == 0;
}

void queue__join (Queue * queue, Item item) {
    Node * node = malloc(sizeof(Node) * 1);
    if (node == NULL) {
        fprintf(stderr, "Something went wrong allocating memory for new node.\n");
        exit(EXIT_FAILURE);
    }
    node->payload = item;
    node->next = NULL;

    Node * prev = NULL;
    Node * curr = queue->elems;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        queue->elems = node;
    } else {
        prev->next = node;
    }
    queue->nact++;
}

bool queue__pop (Queue * queue, Item * popped) {
    if (queue__isempty(queue)) {
        fprintf(stderr, "Can't pop item since the queue is empty.\n");
        return true;
    }
    *popped = queue->elems->payload;
    Node * tmp = queue->elems;
    queue->elems = queue->elems->next;
    free(tmp);
    queue->nact--;
    return false;
}

void queue__print_state (Queue * queue) {
    if (queue->elems == NULL) {
        fprintf(stdout, " -- Queue labeled '%s': []\n", queue->name);
        return;
    }
    fprintf(stdout, " -- Queue labeled '%s': [", queue->name);
    Node * curr = queue->elems;
    while (curr->next != NULL) {
        fprintf(stdout, "%3d, ", curr->payload);
        curr = curr->next;
    }
    fprintf(stdout, "%3d]\n", curr->payload);
}
