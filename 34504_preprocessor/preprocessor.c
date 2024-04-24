#include <stdlib.h>
#include <stdio.h>

#ifndef AVG
#define AVG(x,y) (x+y)/2
#endif

#ifndef AVG_BETTER
#define AVG_BETTER(x,y) (((x)+(y))/2)
#endif

#ifndef AREA
#define AREA(x,y) (x)*(y)
#endif

#ifndef AREA_BETTER
#define AREA_BETTER(x,y) ((x)*(y))
#endif

int main(void) {
    printf("AVG(9,1) = %d\n", AVG(9,1));
    printf("AVG(9.0f,1.0f) = %f\n", AVG(9.0f,1.0f));
    printf("100.0f/AVG(9.0f,1.0f) = %f\n", 100.0f/AVG(9.0f,1.0f));
    printf("100.0f/(AVG(9.0f,1.0f)) = %f\n", 100.0f/(AVG(9.0f,1.0f)));
    printf("\n");

    printf("AVG_BETTER(9,1) = %d\n", AVG_BETTER(9,1));
    printf("AVG_BETTER(9.0f,1.0f) = %f\n", AVG_BETTER(9.0f,1.0f));
    printf("100.0f/AVG_BETTER(9.0f,1.0f) = %f\n", 100.0f/AVG_BETTER(9.0f,1.0f));
    printf("100.0f/(AVG_BETTER(9.0f,1.0f)) = %f\n", 100.0f/(AVG_BETTER(9.0f,1.0f)));
    printf("\n");

    printf("AREA(2,3) = %d\n", AREA(2,3));
    printf("AREA(2.0f,3.0f) = %f\n", AREA(2.0f,3.0f));
    printf("6.0f/AREA(2.0f,3.0f) = %f\n", 6.0f/AREA(2.0f,3.0f));
    printf("6.0f/(AREA(2.0f,3.0f)) = %f\n", 6.0f/(AREA(2.0f,3.0f)));
    printf("\n");

    printf("AREA_BETTER(2,3) = %d\n", AREA_BETTER(2,3));
    printf("AREA_BETTER(2.0f,3.0f) = %f\n", AREA_BETTER(2.0f,3.0f));
    printf("6.0f/AREA_BETTER(2.0f,3.0f) = %f\n", 6.0f/AREA_BETTER(2.0f,3.0f));
    printf("6.0f/(AREA_BETTER(2.0f,3.0f)) = %f\n", 6.0f/(AREA_BETTER(2.0f,3.0f)));

    return EXIT_SUCCESS;
}
