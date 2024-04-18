#include <stdio.h>

#define PI (3.1416f)

int main (void) {

    int radius;
    printf("Enter the radius of the sphere: ");
    scanf("%d", &radius);

    float volume = 4.0f / 3 * PI * radius * radius * radius;
    printf("A sphere of radius %d [units of length] has a volume of %.2f [units of length^3].\n", radius, volume);

}
