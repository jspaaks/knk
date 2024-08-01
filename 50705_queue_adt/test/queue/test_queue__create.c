#include <criterion/criterion.h>
#include "queue/queue.h"
#include <assert.h>
#include <stdio.h>


static size_t nmax1 = 0;
static size_t nmax2 = 0;
static Queue * q1 = NULL;
static Queue * q2 = NULL;
static char * name1 = "q1";
static char * name2 = "q2";


static void setup(void) {
    nmax1 = 4;
    nmax2 = 5;
    q1 = queue__create(nmax1, name1);
    q2 = queue__create(nmax2, name2);
}

static void teardown(void) {
    nmax1 = 0;
    nmax2 = 0;
    q1 = NULL;
    q2 = NULL;
}

Test(queue__create, noop, .init = setup, .fini = teardown) {
    cr_assert(q1 != NULL && q2 != NULL, "Expected both queues to be not NULL");
    cr_assert(q1 != q2, "Expected the queues to be different objects");
    cr_assert(queue__isempty(q1) && queue__isempty(q2), "Expected both queues to be empty");
    cr_assert(queue__get_length(q1) == 0, "Expected first queue to be of length 0");
    cr_assert(queue__get_length(q2) == 0, "Expected second queue to be of length 0");
    cr_assert(queue__get_capacity(q1) == nmax1, "Expected first queue to be of capacity %ld", nmax1);
    cr_assert(queue__get_capacity(q2) == nmax2, "Expected second queue to be of capacity %ld", nmax2);
}
