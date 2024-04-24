#ifndef GEOM_H
#define GEOM_H

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point upper_left;
    struct point lower_right;
};


int calc_area(struct rectangle);
bool contains(struct rectangle, struct point);
struct point calc_center (struct rectangle);
int get_height(struct rectangle);
int get_width(struct rectangle);
struct rectangle move (struct rectangle, int, int);

#endif
