#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef DISP
#define DISP(f,x) printf(#f "(%g) = %g\n", x, f(x))
#endif

#ifndef DISP2
#define DISP2(f,x,y) printf(#f "(%d,%d) = %d\n", x, y, f(x, y))
#endif

int sum(int x, int y) {
    return x + y;
}


int main(void) {
    DISP(sqrt, 3.0f);
    DISP2(sum, 3, 7);
    return EXIT_SUCCESS;
}
