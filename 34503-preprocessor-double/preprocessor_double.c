#include <stdlib.h>
#include <stdio.h>

#ifndef DOUBLE
#define DOUBLE(x) 2*x
#endif

#ifndef DOUBLE_BETTER
#define DOUBLE_BETTER(x) (2*(x))
#endif


int main(void) {
    printf("DOUBLE(1+2) = %d\n", DOUBLE(1+2));
    printf("4/DOUBLE(2) = %d\n", 4/DOUBLE(2));
    printf("DOUBLE_BETTER(1+2) = %d\n", DOUBLE_BETTER(1+2));
    printf("4/DOUBLE_BETTER(2) = %d\n", 4/DOUBLE_BETTER(2));
    return EXIT_SUCCESS;
}
