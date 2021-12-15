#include <stdio.h>

#define PI (3.1416f)

int main (void) {

    int radius = 10;
    float volume = 4.0f / 3 * PI * radius * radius * radius;
    printf("A sphere of radius %d [units of length] has a volume of %.2f [units of length^3].\n", radius, volume);

}
