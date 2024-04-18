#include <stdio.h>

int main (void) {

    int i = 1;
    int j = 2;
    int k = 3;
    printf("%d\n", (i + 5) % (j + 2) / k); // should print '0'

    return 0;

}
