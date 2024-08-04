#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>

static Queue * q = NULL;
static char * name = "q1";

static void setup (void) {
    q = queue__create(name);
}

static void teardown (void) {
    q = NULL;
}

Test(queue__destroy, simple, .init = setup, .fini = teardown) {
    queue__destroy(&q);
    cr_assert(q == NULL, "Expected Queue * to be NULL since it was supposed to be destroyed.");
}
