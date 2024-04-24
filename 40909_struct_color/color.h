#ifndef COLOR_H
#define COLOR_H


struct color {
    int red;
    int green;
    int blue;
};


struct color brighten (struct color);
int clip (int);
struct color darken (struct color);
bool is_equal(struct color, struct color);
int get_red (struct color);
int get_green (struct color);
int get_blue (struct color);
struct color new (int, int, int);
void print (struct color);

#endif
