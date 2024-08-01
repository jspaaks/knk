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

Test(queue__pop, noop, .init = setup, .fini = teardown) {
    Item actual0 = -99;
    Item actual = actual0;
    bool haderr = queue__pop(q, &actual);
    cr_assert(haderr == true, "Should not be able to pop() on an empty queue.");
    cr_assert(actual == actual0, "Popped item should be unchanged but was %d", actual);
}

Test(queue__pop, join_pop, .init = setup, .fini = teardown) {
    assert((queue__get_length(q) == 0) && "Expected queue to be of length 0.");
    Item expected = 100;
    queue__join(q, expected);
    assert((queue__get_length(q) == 1) && "Expected queue to be of length 1.");
    Item actual = -99;
    bool haderr = queue__pop(q, &actual);
    cr_expect(haderr == false, "Popping one element should have been possible when queue length is 1");
    cr_expect(actual == expected, "Expected popped element to be %d but was %d.", expected, actual);
    cr_expect(queue__get_length(q) == 0, "Expected queue to be of length 0.");
}
