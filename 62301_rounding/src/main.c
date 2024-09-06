#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double round_nearest (double, unsigned int);

int main (int argc, char * argv[]) {

    const char * exename = "round";

    if (argc != 1) {
        fprintf(stderr,
                "Usage: %s\n"
                "    Demonstrate rounding to a given number of digits.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    double testvalues[] = { 0.97531, 1.23456, -0.97531, -1.23456 };
    size_t n = sizeof(testvalues) / sizeof(testvalues[0]);
    for (size_t i = 0; i < n; ++i) {
        for (unsigned int ndigits = 0; ndigits < 3; ++ndigits) {
            fprintf(stdout, "% .5f rounded to nearest %u digits = % .3f\n", testvalues[i], ndigits,
                    round_nearest(testvalues[i], ndigits));
        }
    }

    return EXIT_SUCCESS;
}

double round_nearest (double x, unsigned int ndigits) {
    unsigned int f = pow(10, ndigits);
    return (x < 0.0 ? ceil(x * f - 0.5) : floor(x * f + 0.5)) / f;
}
