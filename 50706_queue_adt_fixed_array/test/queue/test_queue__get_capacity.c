#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>

static size_t nmax = 0;
static Queue * q = NULL;
static char * name = "q1";

static void setup (void) {
    nmax = 4;
    q = queue__create(nmax, name);
}

static void teardown (void) {
    nmax = 0;
    q = NULL;
}

Test(queue__get_capacity, simple, .init = setup, .fini = teardown) {
    size_t actual = queue__get_capacity(q);
    cr_assert(actual == nmax, "Expected queue's capacity to be %ld but was %ld.", nmax, actual);
}
