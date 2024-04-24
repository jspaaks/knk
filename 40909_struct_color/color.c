#include <stdio.h>
#include <stdbool.h>
#include "color.h"


const float FACTOR = 1 / 0.7;


struct color brighten (struct color c) {
    if (c.red == 0 && c.green == 0 && c.green == 0) {
        // special case to avoid getting stuck in blackout state
        return new(3, 3, 3);
    }
    int r = clip((int) (c.red < 3 ? 3 : c.red) * FACTOR);
    int g = clip((int) (c.green < 3 ? 3 : c.green) * FACTOR);
    int b = clip((int) (c.blue < 3 ? 3 : c.blue) * FACTOR);
    return new(r, g, b);
}


int clip (int color) {
    if (color < 0) {
        return 0;
    }
    if (color > 255) {
        return 255;
    }
    return color;
}


struct color darken (struct color c) {
    int r = clip((int) c.red / FACTOR);
    int g = clip((int) c.green / FACTOR);
    int b = clip((int) c.blue / FACTOR);
    return new(r, g, b);
}


bool is_equal(struct color c1, struct color c2) {
    return c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue;
}


int get_red (struct color c) {
    return c.red;
}


int get_green (struct color c) {
    return c.green;
}


int get_blue (struct color c) {
    return c.blue;
}


struct color new (int red, int green, int blue) {
    struct color c = {
        .red = clip(red),
        .green = clip(green),
        .blue = clip(blue),
    };
    return c;
}

void print (struct color c) {
    char formatstr[] = "{r:%3d/255, g:%3d/255, b:%3d/255}\n";
    fprintf(stdout, formatstr, get_red(c) , get_green(c), get_blue(c));
}
