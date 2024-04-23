#ifndef SHAPE_H
#define SHAPE_H


struct point {
    int x;
    int y;
};


struct shape {
    enum {CIRCLE, RECTANGLE} kind;                /* RECTANGLE or CIRCLE */
    struct point center;
    union {
        struct {
            int height;
            int width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
};


void print_shape(struct shape, char[]);
int calc_area(struct shape);


#endif
