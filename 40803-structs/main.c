#include <stdio.h>

struct complex {
    double real;
    double imag;
};


struct complex make_complex (double, double);
struct complex add_complex (struct complex, struct complex);


int main (void) {

    struct complex c1 = make_complex (1, 0);
    struct complex c2 = make_complex (0, 1);
    struct complex c3 = add_complex (c1, c2);

    printf("c1 = (% .3f, % .3f)\n", c1.real, c1.imag);
    printf("c2 = (% .3f, % .3f)\n", c2.real, c2.imag);
    printf("c3 = (% .3f, % .3f)\n", c3.real, c3.imag);
}


struct complex add_complex (struct complex c1, struct complex c2) {
    struct complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}


struct complex make_complex (double real, double imag) {
    struct complex c = {.real = real, .imag = imag};
    return c;
}
