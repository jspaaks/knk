#ifndef SHAPE_H
#define SHAPE_H
#define CIRCLE 0
#define RECTANGLE 1


struct point {
    int x;
    int y;
};


struct shape {
    int kind;                /* RECTANGLE or CIRCLE */
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
