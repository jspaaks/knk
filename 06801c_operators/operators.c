#include <stdio.h>

int main (void) {

    int i = 7;
    int j = 8;
    int k = 9;
    printf("%d\n", (i + 10) % k / j); // should print '1'

    return 0;

}
