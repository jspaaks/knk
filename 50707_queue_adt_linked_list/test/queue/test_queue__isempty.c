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

Test(queue__isempty, noop, .init = setup, .fini = teardown) {
    bool actual = queue__isempty(q);
    cr_assert(actual == true, "Expected queue to be empty initially but wasn't");
}
