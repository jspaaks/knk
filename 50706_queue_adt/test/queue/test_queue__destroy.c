#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>

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

Test(queue__destroy, simple, .init = setup, .fini = teardown) {
    queue__destroy(&q);
    cr_assert(q == NULL, "Expected Queue * to be NULL since it was supposed to be destroyed.");
}
