#include <stdio.h>
#include <stdlib.h>

typedef union {
    float as_float;

    struct {
        unsigned int fraction : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } as_struct;
} FloatUnion;

int main (void) {
    FloatUnion f = {
        .as_struct = {
            .sign = 1,
            .exponent = 128,
            .fraction = 0,
         }
    };
    fprintf(stdout, "Printing type union as struct:\n");
    fprintf(stdout, " -- sign: %d\n", f.as_struct.sign);
    fprintf(stdout, " -- exponent: %d\n", f.as_struct.exponent);
    fprintf(stdout, " -- fraction: %d\n", f.as_struct.fraction);
    fprintf(stdout, "Printing that same type union as float:\n");
    fprintf(stdout, " -- float: %.2f\n", f.as_float);
    return EXIT_SUCCESS;
}
