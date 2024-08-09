#include <stdio.h>
#include <math.h>
#include "llist/llist.h"

typedef llist__Printers Printers;

static void printer_pre(FILE * sink, size_t nelems) {
    fprintf(sink, " -- LinkedList[%ld] = {", nelems);
}

static void printer_int_elem(FILE * sink, size_t idx, size_t nelems, void * p) {
    if (idx < nelems - 1) {
        fprintf(sink, "%d, ", *((int *) p)); 
    } else {
        fprintf(sink, "%d", *((int *) p)); 
    }
}

static void printer_float_elem(FILE * sink, size_t idx, size_t nelems, void * p) {
    if (idx < nelems - 1) {
        fprintf(sink, "%.2f, ", *((float *) p)); 
    } else {
        fprintf(sink, "%.2f", *((float *) p)); 
    }
}

static void printer_post(FILE * sink, size_t) {
    fprintf(sink, "}\n");
}

static bool filter(void * p) {
    int elem = *((int *) p);
    return elem == 101;
}

int main (void) {

    int arr1[] = { 100, 101, 102, 103 };

    Printers printers1 = {
        .pre = printer_pre,
        .elem = printer_int_elem,
        .post = printer_post
    };

    fprintf(stdout, "Creating an instance of LinkedList of int\nand adding some items to it:\n");
    LinkedList * lst1 = llist__create();
    llist__print(stdout, lst1, printers1);

    llist__insert(lst1, 0, (void *) &arr1[2]);
    llist__print(stdout, lst1, printers1);
  
    llist__insert(lst1, 0, (void *) &arr1[0]);
    llist__print(stdout, lst1, printers1);
  
    llist__insert(lst1, 2, (void *) &arr1[3]);
    llist__print(stdout, lst1, printers1);
  
    llist__insert(lst1, 1, (void *) &arr1[1]);
    llist__print(stdout, lst1, printers1);

    llist__delete(lst1, filter, false);
    llist__print(stdout, lst1, printers1);

    // ---------------------------------------------------------- //

    float arr2[] = { 200.0f, 201.0f, 202.0f, 203.0f };
  
    Printers printers2 = {
        .pre = NULL,
        .elem = printer_float_elem,
        .post = NULL
    };

    fprintf(stdout, "Creating an instance of LinkedList of float\nand adding some items to it:\n");
    LinkedList * lst2 = llist__create();
    fprintf(stdout, " -- ");
    llist__print(stdout, lst2, printers2);
  
    llist__insert(lst2, 0, (void *) &arr2[2]);
    fprintf(stdout, " -- ");
    llist__print(stdout, lst2, printers2);
  
    llist__insert(lst2, 0, (void *) &arr2[0]);
    fprintf(stdout, " -- ");
    llist__print(stdout, lst2, printers2);
  
    llist__insert(lst2, 2, (void *) &arr2[3]);
    fprintf(stdout, " -- ");
    llist__print(stdout, lst2, printers2);
  
    llist__insert(lst2, 1, (void *) &arr2[1]);
    fprintf(stdout, " -- ");
    llist__print(stdout, lst2, printers2);

    return EXIT_SUCCESS;
}
