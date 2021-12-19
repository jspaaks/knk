#include <stdio.h>


int main (void) {

    int a[10] = { 0 };
    int nelems = (int) sizeof(a) / sizeof(a[0]);

    printf("Enter %d integers: ", nelems);
    for (int ielem = 0; ielem < nelems; ielem++) {
        scanf(" %d", &a[ielem]);
    }

    printf("In reverse order : ");

    for (int ielem = nelems - 1; ielem >= 0; ielem--) {
        printf("%d ", a[ielem]);
    }

    printf("\n");

    return 0;

}
