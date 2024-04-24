#include <stdio.h>

#define NELEMS 10

int main (void) {

    int nelems = NELEMS;
    int a[nelems];

    printf("Enter %d integers: ", nelems);
    for (int ielem = 0; ielem < nelems; ielem++) {
        scanf(" %d", &a[ielem]);
    }

    printf("In reverse order: ");

    for (int ielem = nelems - 1; ielem >= 0; ielem--) {
        printf("%d ", a[ielem]);
    }

    printf("\n");

    return 0;

}
