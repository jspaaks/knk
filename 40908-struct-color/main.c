#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};


const struct color MAGENTA = {.red = 255, .blue = 255};

int main (void) {
    char formatstr[] = "MAGENTA is %d/255 red, %d/255 green, and %d/255 blue.\n";
    fprintf(stdout, formatstr, MAGENTA.red , MAGENTA.green, MAGENTA.blue);
}
