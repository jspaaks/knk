#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;


Complex make_complex (double, double);
Complex add_complex (Complex, Complex);


int main (void) {

    Complex c1 = make_complex (2, 0);
    Complex c2 = make_complex (0, 2);
    Complex c3 = add_complex (c1, c2);

    printf("c1 = (% .3f, % .3f)\n", c1.real, c1.imag);
    printf("c2 = (% .3f, % .3f)\n", c2.real, c2.imag);
    printf("c3 = (% .3f, % .3f)\n", c3.real, c3.imag);
}


Complex add_complex (Complex c1, Complex c2) {
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}


Complex make_complex (double real, double imag) {
    Complex c = {.real = real, .imag = imag};
    return c;
}
