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


Test(queue__isfull, noop, .init = setup, .fini = teardown) {
    cr_assert(queue__isfull(q) == false, "Expected queue to not be full.");
}


Test(queue__isfull, on_full_queue, .init = setup, .fini = teardown) {
    queue__join(q, (Item) 100);
    cr_assert(queue__isfull(q) == false, "Expected queue to not be full.");
    queue__join(q, (Item) 101);
    cr_assert(queue__isfull(q) == false, "Expected queue to not be full.");
    queue__join(q, (Item) 102);
    cr_assert(queue__isfull(q) == false, "Expected queue to not be full.");
    queue__join(q, (Item) 103);
    cr_assert(queue__isfull(q) == true, "Expected queue to be full.");
}
