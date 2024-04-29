#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point upper_left;
    struct point lower_right;
};

struct rectangle * p;

int main (void) {
    struct rectangle rect = {
        .upper_left = {
            .x = 10,
            .y = 25,
        },
        .lower_right = {
            .x = 20,
            .y = 15,
        },
    };
    p = &rect;
    printf("left   = %d\n", (*p).upper_left.x);
    printf("right  = %d\n", (*p).lower_right.x);
    printf("top    = %d\n", (*p).upper_left.y);
    printf("bottom = %d\n", (*p).lower_right.y);
}
