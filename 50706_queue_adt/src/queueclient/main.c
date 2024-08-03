#include "queue/queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    fprintf(stdout, "Create queue named 'q1' of capacity 3.\n");
    Queue * q1 = queue__create(3, "q1");
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Create queue anmed 'q2' of capacity 10.\n");
    Queue * q2 = queue__create(10, "q2");
    queue__print_state(q2);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Add 100 to q1\n");
    queue__join(q1, (Item) 100);
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Pop the first item off q1.\n");
    Item popped = -99;
    bool haderr = queue__pop(q1, &popped);
    if (!haderr) {
        fprintf(stdout, " -- Popped item from q1 was %3d\n", popped);
    } else {
        fprintf(stderr, " -- There was an error popping an element from q1\n");
    }
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    for (int i = 101; i < 104; i++) {
        fprintf(stdout, "Item %3d joins q1\n", i);
        queue__join(q1, (Item) i);
        queue__print_state(q1);
        fprintf(stdout, "\n");
    }

    // ---

    if (queue__isfull(q1)) {
        fprintf(stdout, "q1 is now full\n");
    }
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    for (int i = 200; i < 209; i++) {
        fprintf(stdout, "Item %d joins q2\n", i);
        queue__join(q2, (Item) i);
        queue__print_state(q2);
        fprintf(stdout, "\n");
    }

    // ---

    fprintf(stdout, "Popping 3 items off q2\n");
    popped = -99;
    for (size_t i = 0; i < 3; i++) {
        queue__pop(q2, &popped);
        fprintf(stdout, " -- Popped item from q2 was %d\n", popped);
        queue__print_state(q2);
        fprintf(stdout, "\n");
    }

    // ---

    for (int i = 209; i < 213; i++) {
        fprintf(stdout, "Item %d joins q2\n", i);
        queue__join(q2, (Item) i);
        queue__print_state(q2);
        fprintf(stdout, "\n");
    }

    // ---

    fprintf(stdout, "Popping the first item off q1\n");
    popped = -99;
    queue__pop(q1, &popped);
    fprintf(stdout, " -- Popped item from q1 was %d\n", popped);
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Popping the first item off q1\n");
    popped = -99;
    queue__pop(q1, &popped);
    fprintf(stdout, " -- Popped item from q1 was %d\n", popped);
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Item 104 joins q1\n");
    queue__join(q1, (Item) 104);
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Time to put q1 out to pasture\n");
    queue__destroy(&q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Popping the first item off q2\n");
    popped = -99;
    queue__pop(q2, &popped);
    fprintf(stdout, " -- Popped item from q2 was %d\n", popped);
    queue__print_state(q2);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Time to put q2 out to pasture\n");
    queue__destroy(&q2);

    // ---

    exit(EXIT_SUCCESS);
}
