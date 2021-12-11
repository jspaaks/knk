#include <stdio.h>

int main (void) {

    int i = 2;
    int j = 3;
    printf("%d\n", (i + 10) % j); // should print '0'

    return 0;

}
