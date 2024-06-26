#include <stdio.h>


int main (void) {

    struct {
        double real;
        double imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

    printf("before\n");
    printf("c1 = (% .3f, % .3f)\n", c1.real, c1.imaginary);
    printf("c2 = (% .3f, % .3f)\n", c2.real, c2.imaginary);

    c1 = c2;
    printf("after\n");
    printf("c1 = (% .3f, % .3f)\n", c1.real, c1.imaginary);
    printf("c2 = (% .3f, % .3f)\n", c2.real, c2.imaginary);

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("c3 = (% .3f, % .3f)\n", c3.real, c3.imaginary);
}
