#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static Queue * q = NULL;
static char * name = "q1";

static void setup (void) {
    q = queue__create(name);
}

static void teardown (void) {
    q = NULL;
}

Test(queue__join, simple, .init = setup, .fini = teardown) {
    int a = 235;
    queue__join(q, (void *) &a);
    cr_assert(queue__get_length(q) == 1, "Expected queue to be of length 1.");
}

Test(queue__join, three_times, .init = setup, .fini = teardown) {
    size_t nmax = 3;
    int data[] = {100, 101, 102};
    for (size_t i = 0; i < nmax; i++) {
        queue__join(q, (void *) &data[i]);
    }
    cr_assert(queue__get_length(q) == nmax, "Expected queue's length to be %ld", nmax);
}
