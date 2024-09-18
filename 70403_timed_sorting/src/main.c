#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);
int comparator (const void *, const void *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    const size_t nsamples[] = { 1000, 10000, 100000 };
    const size_t nbytes_per_elem = sizeof(int);
    size_t ntries = sizeof(nsamples) / sizeof(nsamples[0]);

    for (size_t i = 0; i < ntries; ++i) {
        size_t nelems = nsamples[i];
        int * arr = malloc(nbytes_per_elem * nelems);
        for (size_t i = 0; i < nelems; ++i) {
            arr[i] = nelems - i;
        }
        clock_t before = clock();
        qsort(&arr[0], nelems, nbytes_per_elem, comparator);
        clock_t after = clock();
        free(arr);
        fprintf(stdout, "Sorting %zu integers took %f seconds.\n", nelems,
                ((double) (after - before)) / CLOCKS_PER_SEC);
    }

    return EXIT_SUCCESS;
}

int comparator (const void * a, const void * b) {
    const int * aa = (int *) a;
    const int * bb = (int *) b;
    return *aa - *bb;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate measuring the duration of sort operations on a\n"
            "   reverse-sorted array of integers of various lengths.\n",
            exename);
}
