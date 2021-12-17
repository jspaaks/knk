#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main (void) {

    double y = 1.0;
    double y_prev = 100000;
    double tolerance = 0.00001;
    int i = 0;
    bool keepgoing = true;

    double avg;
    double x;

    printf("This program determines the square root y of x by iteration according to\n");
    printf("Newton's method. Enter a positive value for x (floats allowed): ");
    scanf(" %lf", &x);

    printf("\n");
    printf("i    |y         |x/y       |(y+x/y)/2 |y*y       \n");
    printf("-----|----------|----------|----------|----------\n");

    do {

        avg = (y + x/y) / 2;

        printf("%5d|%10.5f|%10.5f|%10.5f|%10.5f\n", i, y, x/y, avg, y*y);

        y_prev = y;

        y = avg;

        keepgoing = fabs(y - y_prev) >= tolerance * y;

        i += 1;

    } while (keepgoing);

    printf("\n");
    printf("The square root of %.5f is approximately %.5f\n", x, y);
    printf("\n");

    return 0;

}
