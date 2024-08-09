#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "llist/llist.h"
#include <unistd.h>

typedef llist__Printers Printers;

typedef struct {
    bool marked;
    int data;
} MyStruct;

static LinkedList * lst = NULL; 

void setup (void) {
    cr_redirect_stdout();
    lst = llist__create();
}

static void teardown (void) {
    llist__destroy(&lst);
}

static void printer_int_elem (FILE * sink, size_t idx, size_t nelems, void * elem) {
    if (idx < nelems - 1) {
        fprintf(sink, "%d, ", *((int *) elem)); 
    } else {
        fprintf(sink, "%d", *((int *) elem)); 
    }
}

static void printer_my_struct_elem (FILE * sink, size_t idx, size_t nelems, void * elem) {
    MyStruct my_struct = *((MyStruct *) elem);
    if (idx < nelems - 1) {
        fprintf(sink, "{.marked: %s, .data: %d}, ", my_struct.marked ? "true" : "false", my_struct.data);
    } else {
        fprintf(sink, "{.marked: %s, .data: %d}", my_struct.marked ? "true" : "false", my_struct.data);
    }
}


static Printers int_printers = {
    .pre = NULL,
    .elem = printer_int_elem,
    .post = NULL
};

static Printers my_struct_printers = {
    .pre = NULL,
    .elem = printer_my_struct_elem,
    .post = NULL
};

static bool filter (void * p) {
    MyStruct my_struct = *((MyStruct *) p);
    return my_struct.data % 2 == 0;
}

Test(llist__create, first, .init = setup, .fini = teardown) {
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[]\n");
}

Test(llist__destroy, first, .init = setup) {
    llist__destroy(&lst);
    cr_assert(lst == NULL, "Instance of LinkedList should be NULL after it has been destroyed.\n");
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}

Test(llist__get_length, after_noop, .init = setup, .fini = teardown) {
    size_t expected = 0;
    size_t actual = llist__get_length(lst);
    cr_assert(actual == expected, "Instance of LinkedList should be of length %ld but was %ld.\n", expected, actual);
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[]\n");
}

Test(llist__get_length, after_inserting_four_items, .init = setup, .fini = teardown) {
    int arr[] = {100, 101, 102, 103};
    llist__insert(lst, 0, (void *) &arr[3]);
    llist__insert(lst, 0, (void *) &arr[2]);
    llist__insert(lst, 0, (void *) &arr[1]);
    llist__insert(lst, 0, (void *) &arr[0]);
    constexpr size_t expected = sizeof(arr) / sizeof(arr[0]);
    size_t actual = llist__get_length(lst);
    cr_assert(actual == expected, "Instance of LinkedList should be of length %ld but was %ld.\n", expected, actual);
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[100, 101, 102, 103]\n");
}

Test(llist__insert, four_items_out_of_order, .init = setup, .fini = teardown) {
    int arr[] = {100, 101, 102, 103};
    llist__insert(lst, 0, (void *) &arr[2]);
    llist__insert(lst, 0, (void *) &arr[0]);
    llist__insert(lst, 2, (void *) &arr[3]);
    llist__insert(lst, 1, (void *) &arr[1]);
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[100, 101, 102, 103]\n");
}

Test(llist__append, four_items, .init = setup, .fini = teardown) {
    int arr[] = {100, 101, 102, 103};
    llist__append(lst, (void *) &arr[0]);
    llist__append(lst, (void *) &arr[1]);
    llist__append(lst, (void *) &arr[2]);
    llist__append(lst, (void *) &arr[3]);
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[100, 101, 102, 103]\n");
}

Test(llist__prepend, four_items, .init = setup, .fini = teardown) {
    int arr[] = {100, 101, 102, 103};
    llist__prepend(lst, (void *) &arr[3]);
    llist__prepend(lst, (void *) &arr[2]);
    llist__prepend(lst, (void *) &arr[1]);
    llist__prepend(lst, (void *) &arr[0]);
    llist__print(stdout, lst, int_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[100, 101, 102, 103]\n");
}

Test(llist__delete, global, .init = setup, .fini = teardown) {
    MyStruct arr[] = {
        {
            .marked = false,
            .data = 100
        },
        {
            .marked = false,
            .data = 101
        },
        {
            .marked = false,
            .data = 102
        },
        {
            .marked = false,
            .data = 103
        }
    };
    llist__prepend(lst, (void *) &arr[3]);
    llist__prepend(lst, (void *) &arr[2]);
    llist__prepend(lst, (void *) &arr[1]);
    llist__prepend(lst, (void *) &arr[0]);
    llist__delete(lst, filter, true);
    llist__print(stdout, lst, my_struct_printers);
    fflush(stdout);
    cr_assert_stdout_eq_str("[{.marked: false, .data: 101}, {.marked: false, .data: 103}]\n");
}
