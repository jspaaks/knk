#include <stdbool.h>
#include "geom.h"


int calc_area(struct rectangle rect) {
    int width = get_width(rect);
    int height = get_height(rect);
    return width * height;
}


bool contains(struct rectangle rect, struct point p) {
    return rect.upper_left.x <= p.x && p.x <= rect.lower_right.x &&
           rect.lower_right.y <= p.y  && p.y <= rect.upper_left.y;
}


struct point calc_center(struct rectangle rect) {
    int width = get_width(rect);
    int height = get_height(rect);
    struct point center = {
        .x = rect.upper_left.x + width / 2,
        .y = rect.lower_right.y + height / 2
    };
    return center; 
}


int get_height(struct rectangle rect) {
    return rect.upper_left.y - rect.lower_right.y;
}


int get_width(struct rectangle rect) {
    return rect.lower_right.x - rect.upper_left.x;
}


struct rectangle move (struct rectangle rect, int dx, int dy) {
    rect.upper_left.x += dx;
    rect.lower_right.x += dx;
    rect.upper_left.y += dy;
    rect.lower_right.y += dy;
    return rect;
}
