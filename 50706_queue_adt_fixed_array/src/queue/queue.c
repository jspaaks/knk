#include "queue/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr size_t queue_name_length = 100;

struct queue {
    size_t ihead;
    size_t itail;
    size_t nact;
    size_t nmax;
    char name[queue_name_length];
    Item * elems;
};

Queue * queue__create (size_t nmax, char * name) {
    Queue * q = malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Error allocating memory for new queue instance.\n");
        exit(EXIT_FAILURE);
    }
    q->elems = malloc(sizeof(Item) * nmax);
    if (q->elems == NULL) {
        fprintf(stderr, "Error allocating memory for new queue instance.\n");
        exit(EXIT_FAILURE);
    }
    q->nmax = nmax;
    q->nact = 0;
    q->ihead = 0;
    q->itail = 0;
    strncpy(q->name, name, queue_name_length - 1);
    return q;
}

void queue__destroy (Queue ** queue) {
    Queue ** tmp = queue;
    free((*queue)->elems);
    free(*queue);
    *tmp = NULL;
}

size_t queue__get_capacity (const Queue * queue) {
    return queue->nmax;
}

size_t queue__get_length (const Queue * queue) {
    return queue->nact;
}

bool queue__isfull (const Queue * queue) {
    return queue->nact == queue->nmax;
}

bool queue__isempty (const Queue * queue) {
    return queue->nact == 0;
}

void queue__join (Queue * queue, Item item) {
    if (queue__isfull(queue)) {
        fprintf(stderr, "Item can't join the queue since it's at capacity.\n");
    } else {
        size_t i = queue->itail;
        queue->elems[i] = item;
        i++;
        queue->itail = i % queue->nmax;
        queue->nact++;
    }
}

bool queue__pop (Queue * queue, Item * popped) {
    if (queue__isempty(queue)) {
        fprintf(stderr, "Can't pop item since the queue is empty.\n");
        return true;
    }
    size_t i = queue->ihead;
    *popped = queue->elems[i];
    i++;
    queue->ihead = i % queue->nmax;
    queue->nact--;
    return false;
}

void queue__print_state (Queue * queue) {
    if (queue->nmax == 0) {
        fprintf(stdout, " -- Queue labeled '%s': []", queue->name);
        return;
    }
    fprintf(stdout, " -- Queue labeled '%s': [", queue->name);
    size_t ih = queue->ihead;
    size_t it = queue->itail;
    bool iswrapped = queue->nact > 0 && it <= ih;
    for (size_t i = 0; i < queue->nmax; i++) {
        if (iswrapped) {
            if (it <= i && i < ih) {
                fprintf(stdout, "___, ");
            } else {
                fprintf(stdout, "%3d, ", queue->elems[i]);
            }
        } else {
            if (ih <= i && i < it) {
                fprintf(stdout, "%3d, ", queue->elems[i]);
            } else {
                fprintf(stdout, "___, ");
            }
        }
    }
    fprintf(stdout, "\b\b] %s\n", iswrapped ? "wrapped" : "not wrapped");
}
