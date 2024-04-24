#include <stdio.h>
#include <stdbool.h>
#include "geom.h"


int main (void) {
    const int xl = 10;
    const int xr = 310;
    const int yb = 45;
    const int yt = 245;
    const struct point ul = {.x = xl, .y = yt};
    const struct point lr = {.x = xr, .y = yb};
    const struct rectangle rect = {.upper_left = ul, .lower_right = lr};
    const int a = calc_area(rect);
    const struct point c = calc_center(rect);
    const struct rectangle moved = move(rect, 10, 20);
    fprintf(stdout, "-------------------------------------------\n");
    fprintf(stdout, "left         = %d\n", rect.upper_left.x);
    fprintf(stdout, "right        = %d\n", rect.lower_right.x);
    fprintf(stdout, "bottom       = %d\n", rect.lower_right.y);
    fprintf(stdout, "top          = %d\n", rect.upper_left.y);
    fprintf(stdout, "area         = %d\n", a);
    fprintf(stdout, "center       = %d,%d\n", c.x, c.y);
    {
        const struct point p = {.x = 45, .y = 900};
        fprintf(stdout, "rect contains {.x = %d, .y = %d} = %s\n", p.x, p.y, contains(rect, p) ? "true" : "false");
    }
    {
        const struct point p = {.x = 45, .y = 100};
        fprintf(stdout, "rect contains {.x = %d, .y = %d} = %s\n", p.x, p.y, contains(rect, p) ? "true" : "false");
    }
    fprintf(stdout, "-------------------------------------------\n");
    fprintf(stdout, "move(rect, 10, 20)\n");
    fprintf(stdout, "left         = %d\n", moved.upper_left.x);
    fprintf(stdout, "right        = %d\n", moved.lower_right.x);
    fprintf(stdout, "bottom       = %d\n", moved.lower_right.y);
    fprintf(stdout, "top          = %d\n", moved.upper_left.y);
    fprintf(stdout, "-------------------------------------------\n");
}
