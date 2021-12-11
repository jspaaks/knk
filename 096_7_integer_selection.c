#include <stdio.h>


int main (void) {

    int i0, i1, i2, i3;

    printf("Please enter 4 integers 0-9999 separated by spaces: ");
    scanf(" %d %d %d %d", &i0, &i1, &i2, &i3);

    int largest = i0;

    if (i1 > largest) {
        largest = i1;
    }
    if (i2 > largest) {
        largest = i2;
    }
    if (i3 > largest) {
        largest = i3;
    }

    int smallest = i0;

    if (i1 < smallest) {
        smallest = i1;
    }
    if (i2 < smallest) {
        smallest = i2;
    }
    if (i3 < smallest) {
        smallest = i3;
    }

    printf("smallest: %d\n", smallest);
    printf("largest: %d\n", largest);

    return 0;

}
