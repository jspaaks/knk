#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>

static Queue * q = NULL;
static char * name = "q1";

static void setup (void) {
    q = queue__create(name);
}

static void teardown (void) {
    q = NULL;
}

Test(queue__get_length, on_empty_queue, .init = setup, .fini = teardown) {
    size_t actual = queue__get_length(q);
    cr_assert(actual == 0, "Expected queue's length to be 0 but was %ld.", actual);
}

Test(queue__get_length, on_full_queue, .init = setup, .fini = teardown) {
    size_t nmax = 4;
    char data[] = {100, 101, 102, 103};
    for (size_t i = 0; i < nmax; i++) {
        queue__join(q, (void *) &data[i]);
    }
    size_t actual = queue__get_length(q);
    cr_assert(actual == nmax, "Expected queue's length to be %ld but was %d.", nmax, actual);
}
