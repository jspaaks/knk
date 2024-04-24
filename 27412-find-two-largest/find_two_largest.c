#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main (void) {

    int array[] = {1, 2, 3, 5, 3, 654, 67, 23, 21, 45, 67, 987, 9, 43, 23};
    int n = (int) (sizeof(array) / sizeof(array[0]));

    int largest = array[0];
    int second_largest = array[0];

    find_two_largest(array, n, &largest, &second_largest);
    printf("The two largest values in the array are %d and %d.\n", largest, second_largest);
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {

    int *this = &a[0];
    // largest = &a[0];
    // second_largest = &a[0];

    for (int i = 0; i < n; i++) {
        if (*this > *largest) {
            printf("%2d: *this (%d) is bigger than *largest (%d)\n", i, *this, *largest);
            *second_largest = *largest;
            *largest = *this;
        } else if (*this > *second_largest ) {
            printf("%2d: *this (%d) is bigger than *second_largest (%d)\n", i, *this, *second_largest);
            *second_largest = *this;
        }
        this++;
    }
    return;
}
