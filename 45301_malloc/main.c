#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


void * my_malloc (size_t);



void * my_malloc (size_t size) {
    void * p = malloc(size);
    if (p == NULL) {
        printf("Error: memory allocation didn't work.");
        exit(EXIT_FAILURE);
    }
    return p;
}


int main (void) {
    printf("INT_MAX = %d\n", INT_MAX);
    long n = 2113060647;
    printf("n       = %ld\n", n);
    int * p = my_malloc(n * sizeof (int *));
    for (long i = 0; i < n; i++) {
        *(p + i) = i;
    }
    for (long i = 0; i < n; i++) {
        if ((i + 1) % 100000 == 0) {
            printf("%d\n", *(p + i));
        }
    }
    while (true) {
        ;
    }
}
