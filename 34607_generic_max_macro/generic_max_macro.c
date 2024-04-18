#include <stdio.h>
#include <stdlib.h>

#define GENERIC_MAX(type) \
type type##_max(type x, type y) { return x > y ? x : y; }

GENERIC_MAX(long)

int main(void) {
    printf("gcc -E <this file.c> to see the macro expansion.\n");
    long a = 1;
    long b = 10;
    long max = long_max(a, b);
    printf("The maximum of %ld and %ld is %ld\n", a, b, max);
    return EXIT_SUCCESS;
}
