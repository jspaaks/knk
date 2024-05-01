#ifndef STACK_H
#define STACK_H

struct node {
    int payload;
    struct node * next;
};


bool is_empty (void);
int len (void);
struct node * last (void);
void make_empty (void);
int pop (void);
bool push (int i);

#endif
