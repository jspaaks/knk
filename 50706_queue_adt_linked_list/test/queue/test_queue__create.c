#include "queue/queue.h"
#include <assert.h>
#include <criterion/criterion.h>
#include <stdio.h>

static Queue * q1 = NULL;
static Queue * q2 = NULL;
static char * name1 = "q1";
static char * name2 = "q2";

static void setup (void) {
    q1 = queue__create(name1);
    q2 = queue__create(name2);
}

static void teardown (void) {
    q1 = NULL;
    q2 = NULL;
}

Test(queue__create, noop, .init = setup, .fini = teardown) {
    cr_assert(q1 != NULL && q2 != NULL, "Expected both queues to be not NULL");
    cr_assert(q1 != q2, "Expected the queues to be different objects");
    cr_assert(queue__isempty(q1) && queue__isempty(q2), "Expected both queues to be empty");
    cr_assert(queue__get_length(q1) == 0, "Expected first queue to be of length 0");
    cr_assert(queue__get_length(q2) == 0, "Expected second queue to be of length 0");
}
