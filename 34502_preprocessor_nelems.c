#include <stdlib.h>
#include <stdio.h>

#ifndef NELEMS
#define NELEMS(x) (sizeof(x) / sizeof(x[0]))
#endif


int main(void) {
    char items[12] = "";
    int numbers[4] = {0, 2, 3};
    printf("NELEMS(items) = %ld\n", NELEMS(items));
    printf("NELEMS(numbers) = %ld\n", NELEMS(numbers));
    return EXIT_SUCCESS;
}
