#include <stdio.h>


void find_two_largest (int a[], int n, int *largest, int *second_largest);


void find_two_largest (int a[], int n, int *largest, int *second_largest) {

    *largest = a[0];
    *second_largest = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        }
    }

    return;

}

int main (void) {

    int a[] = {51, 82, 23, 40, 25, 56, 97, 58};
    int n = (int) ( sizeof(a) / sizeof(a[0]) );
    int max1;
    int max2;

    find_two_largest(a, n, &max1, &max2);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("%d is the largest number, followed by %d\n", max1, max2);

    return 0;

}
