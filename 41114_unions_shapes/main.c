#include <stdio.h>
#include "shape.h"

void print_hrule (void);


void print_hrule (void) {
    fprintf(stdout, "----------------------------------\n");
}


int main (void) {

    struct shape circle1 = {
        .kind = CIRCLE,
        .center = {
            .x = 23,
            .y = 45
        },
        .u.circle = {
            .radius = 6
        }
    };

    struct shape rect1 = {
        .kind = RECTANGLE,
        .center = {
            .x = 345,
            .y = 111
        },
        .u.rectangle = {
            .height = 100,
            .width = 120
        }
    };

    print_hrule();
    print_shape(circle1, "circle1");
    fprintf(stdout, " %-19s = %d\n", ".area", calc_area(circle1));
    print_hrule();

    print_shape(rect1, "rect1");
    fprintf(stdout, " %-19s = %d\n", ".area", calc_area(rect1));
    print_hrule();

    return 0;
}
