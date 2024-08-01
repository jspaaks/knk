#include <criterion/criterion.h>
#include "queue/queue.h"
#include <assert.h>
#include <stdio.h>

static size_t nmax = 0;
static Queue * q = NULL;
static char * name = "q1";


static void setup(void) {
    nmax = 4;
    q = queue__create(nmax, name);
}

static void teardown(void) {
    nmax = 0;
    q = NULL;
}


Test(queue__get_length, on_empty_queue, .init = setup, .fini = teardown) {
    size_t actual = queue__get_length(q);
    cr_assert(actual == 0, "Expected queue's length to be 0 but was %ld.", actual);
}


Test(queue__get_length, on_full_queue, .init = setup, .fini = teardown) {
    for (size_t i = 0; i < nmax; i++) {
        queue__join(q, (Item)(100 + i));
    }
    size_t actual = queue__get_length(q);
    cr_assert(actual == nmax, "Expected queue's length to be %ld but was %d.", nmax, actual);
}
