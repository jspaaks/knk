#include "queue/queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    struct {
        int ints[4];
        char * strings[3];
    } data = {
        .ints = {100, 101, 102, 103},
        .strings = {
            "the first",
            "the second",
            "and finally, the last"
        }
    };

    fprintf(stdout, "Create queue named 'Queue[int]'.\n");
    Queue * q1 = queue__create("Queue[int]");
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Create queue named 'Queue[str]'.\n");
    Queue * q2 = queue__create("Queue[str]");
    queue__print_state(q2);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Add 100 to Queue[int]\n");
    queue__join(q1, (void *) &data.ints[0]);
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Pop the first item off Queue[int].\n");
    void * popped = NULL;
    bool haderr = queue__pop(q1, &popped);
    if (!haderr) {
        fprintf(stdout, " -- Popped item from Queue[int] was %3d\n", *((int *)(popped)));
    } else {
        fprintf(stderr, " -- There was an error popping an element from Queue[int]\n");
    }
    queue__print_state(q1);
    fprintf(stdout, "\n");

    // ---

    for (size_t i = 0; i < 3; i++) {
        fprintf(stdout, "Item '%s' joins Queue[str]\n", data.strings[i]);
        queue__join(q2, (void *) data.strings[i]);
        queue__print_state(q2);
        fprintf(stdout, "\n");
    }

    // ---

    fprintf(stdout, "Time to put Queue[int] out to pasture\n");
    queue__destroy(&q1);
    fprintf(stdout, "\n");

    // ---

    fprintf(stdout, "Pop items off Queue[str].\n");
    size_t nact = queue__get_length(q2);
    for (size_t i = 0; i < nact; i++) {
        void * popped = NULL;
        bool haderr = queue__pop(q2, &popped);
        if (!haderr) {
            fprintf(stdout, " -- Popped item from Queue[str] was '%s'\n", (char *) popped);
        } else {
            fprintf(stderr, " -- There was an error popping an element from Queue[str]\n");
        }
        queue__print_state(q2);
        fprintf(stdout, "\n");
    }
    // ---

    fprintf(stdout, "Time to put Queue[str] out to pasture\n");
    queue__destroy(&q2);

    // ---

    exit(EXIT_SUCCESS);
}
