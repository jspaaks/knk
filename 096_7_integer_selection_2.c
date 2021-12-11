#include <stdio.h>


int main (void) {

    int i0, i1, i2, i3;

    printf("Please enter 4 integers 0-9999 separated by spaces: ");
    scanf(" %d %d %d %d", &i0, &i1, &i2, &i3);

    // this implementation uses 4 if statements (at the cost of clarity)
    int tmp;

    if (i0 > i1) {
        // elements 0 and 1 out of order--switch them
        tmp = i0;
        i0 = i1;
        i1 = tmp;
    }
    if (i2 > i3) {
        // elements 2 and 3 out of order--switch them
        tmp = i2;
        i2 = i3;
        i3 = tmp;
    }

    int smallest = i0;
    int largest = i1;


    if (i2 < smallest) {
        smallest = i2;
    }

    if (i3 > largest) {
        largest = i3;
    }

    printf("smallest: %d\n", smallest);
    printf("largest: %d\n", largest);

    return 0;

}
