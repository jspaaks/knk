#include <stdio.h>
#include <math.h>
#include "shape.h"


int calc_area(struct shape s) {
        switch (s.kind) {
            case CIRCLE: {
                return (int) M_PI * pow(s.u.circle.radius, 2);
            }
            case RECTANGLE: {
                return s.u.rectangle.height * s.u.rectangle.width;
            }
            default: {
                fprintf(stderr, "Something went wrong.\n");
                return -1;
            }
        }
}

void print_shape(struct shape s, char name[]) {
        switch (s.kind) {
            case CIRCLE: {
                fprintf(stdout, "%s\n", name);
                fprintf(stdout, " .kind               = %s\n", s.kind == CIRCLE ? "CIRCLE" : "RECTANGLE");
                fprintf(stdout, " .center.x           = %d\n", s.center.x);
                fprintf(stdout, " .center.y           = %d\n", s.center.y);
                fprintf(stdout, " .u.circle.radius    = %d\n", s.u.circle.radius);
                break;
            }
            case RECTANGLE: {
                fprintf(stdout, "%s\n", name);
                fprintf(stdout, " .kind               = %s\n", s.kind == CIRCLE ? "CIRCLE" : "RECTANGLE");
                fprintf(stdout, " .center.x           = %d\n", s.center.x);
                fprintf(stdout, " .center.y           = %d\n", s.center.y);
                fprintf(stdout, " .u.rectangle.height = %d\n", s.u.rectangle.height);
                fprintf(stdout, " .u.rectangle.width  = %d\n", s.u.rectangle.width);
                break;
            }
            default: {
                fprintf(stderr, "Something went wrong.\n");
            }
        }
}
