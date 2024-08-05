#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef struct queue Queue;

Queue * queue__create (char *);
void queue__destroy (Queue **);
size_t queue__get_length (const Queue *);
bool queue__isempty (const Queue *);
void queue__join (Queue *, void *);
bool queue__pop (Queue *, void **);
void queue__print_state (Queue *);

#endif

