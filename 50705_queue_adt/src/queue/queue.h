#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef int Item;

typedef struct queue Queue;

Queue * queue__create (size_t, char *);
void    queue__destroy (Queue **);
size_t  queue__get_capacity (const Queue *);
size_t  queue__get_length (const Queue *);
bool    queue__isfull (const Queue *);
bool    queue__isempty (const Queue *);
void    queue__join (Queue *, Item);
bool    queue__pop (Queue *, Item *);
void    queue__print_state(Queue *);

#endif
