#include <stdio.h>


int main (void) {

    int a[] = {5, 15, 24, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    printf("*(p + 3) = %d\n", *(p + 3));
    printf("*(q - 3) = %d\n", *(q - 3));
    printf("q - p = %ld\n", q - p);
    printf("p < q = %d\n", p < q);
    printf("*p < *q = %d\n", *p < *q);

    return 0;

}
