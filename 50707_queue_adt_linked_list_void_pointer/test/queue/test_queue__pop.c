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

Test(queue__pop, noop, .init = setup, .fini = teardown) {
    void * popped = NULL;
    bool haderr = queue__pop(q, &popped);
    cr_assert(haderr == true, "Should not be able to pop() on an empty queue.");
    cr_assert(popped == NULL, "Popped item should be unchanged but was %p", popped);
}

Test(queue__pop, join_pop, .init = setup, .fini = teardown) {
    assert((queue__get_length(q) == 0) && "Expected queue to be of length 0.");
    int expected = 100;
    queue__join(q, (void *) &expected);
    assert((queue__get_length(q) == 1) && "Expected queue to be of length 1.");
    void * popped = NULL;
    bool haderr = queue__pop(q, &popped);
    int actual = *((int *) popped);
    cr_expect(haderr == false, "Popping one element should have been possible when queue length is 1");
    cr_expect(actual == expected, "Expected popped element to be %d but was %d.", expected, actual);
    cr_expect(queue__get_length(q) == 0, "Expected queue to be of length 0.");
}
