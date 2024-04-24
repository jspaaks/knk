#include <stdio.h>


int main (void) {

    int a[] = {5, 15, 24, 54, 14, 2, 52, 72};
    int *low = &a[0];
    int *middle;
    int *high = &a[7];

    // adding a pointer to a pointer is illegal
    // middle = (low + high) / 2;

    // but subtraction is ok (note the integer division though)
    middle = low + (high - low) / 2;

    printf("high - low = %ld\n", high - low);
    printf("*middle = %d\n", *middle);

    return 0;

}
