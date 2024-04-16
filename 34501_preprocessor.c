#include <stdlib.h>
#include <stdio.h>

#ifndef CUBE
#define CUBE(x) ((x) * (x) * (x))
#endif

#ifndef REM4
#define REM4(x) ((x) % 4)
#endif

#ifndef OVER100
#define OVER100(x,y) ((x) * (y) > 100 ? 1 : 0)
#endif

int main (void) {
    for (int i = 0; i <= 10; i++) {
        printf("CUBE(%d) = %d\n", i, CUBE(i));
    }
    printf("\n");

    for (int i = 0; i <= 10; i++) {
        printf("REM4(%d) = %d\n", i, REM4(i));
    }
    printf("\n");

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 10; j++) {
            printf("OVER100(%d, %d) = %d\n", i, j, OVER100(i, j));
        }
    }
    return EXIT_SUCCESS;
}
