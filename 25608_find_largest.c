#include <stdio.h>


int *find_largest(int a[], int n);



int *find_largest(int a[], int n) {

    int ilargest = 0;
    int largest = a[ilargest];

    for (int i = 1; i < n; i++) {

        if (a[i] > largest) {
            largest = a[i];
            ilargest = i;
        }
    }

    return &a[ilargest];

}


int main (void) {

    int array[] = {1, 2, 3, 5, 3, 654, 67, 23, 21, 45, 67, 987, 9, 43, 23};
    int n = (int) (sizeof(array) / sizeof(array[0]));

    int *largest_ptr = find_largest(array, n);

    printf("The largest value in array is %d\n", *largest_ptr);

    return 0;

}
