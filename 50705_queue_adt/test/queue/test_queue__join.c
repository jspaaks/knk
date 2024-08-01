#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "queue/queue.h"
#include <assert.h>


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

static void redirect_stdout(void) {
    cr_redirect_stdout();
}

static void redirect_stderr(void) {
    cr_redirect_stderr();
}

static void setup_with_redirect(void) {
    setup();
    redirect_stdout();
    redirect_stderr();
}


Test(queue__join, simple, .init = setup, .fini = teardown) {
    queue__join(q, (Item) 235);
    cr_assert(queue__get_length(q) == 1, "Expected queue to be of length 1.");
}


Test(queue__join, to_capacity, .init = setup, .fini = teardown) {
    queue__join(q, (Item) 100);
    queue__join(q, (Item) 101);
    queue__join(q, (Item) 102);
    queue__join(q, (Item) 103);
    cr_assert(queue__get_length(q) == 4, "Expected queue's length to be %ld", nmax);
    cr_assert(queue__get_length(q) == queue__get_capacity(q), "Expected queue to be at capacity");
}


Test(queue__join, past_capacity, .init = setup_with_redirect, .fini = teardown) {
    queue__join(q, (Item) 100);
    queue__join(q, (Item) 101);
    queue__join(q, (Item) 102);
    queue__join(q, (Item) 103);
    queue__join(q, (Item) 104);
    cr_assert_stderr_eq_str("Item can't join the queue since it's at capacity.\n");
    cr_assert(queue__get_length(q) == 4, "Expected queue's length to be %ld", nmax);
    cr_assert(queue__get_length(q) == queue__get_capacity(q), "Expected queue to be at capacity");
}
