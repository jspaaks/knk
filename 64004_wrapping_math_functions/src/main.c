#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRY_MATH_FCN(f, x) try_math_fcn(f, x, "Error in call to " #f)

typedef double (*Mathfcn)(double);

void show_usage (FILE *);
double try_math_fcn (Mathfcn, double, char *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    double x;
    sscanf(argv[1], " %lf", &x);

    double y = TRY_MATH_FCN(sqrt, x);
    fprintf(stdout, "Sqrt of %lf is %lf.\n", x, y);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s X\n"
            "    Calculate the value of sqrt(X).\n",
            exename);
}

double try_math_fcn (Mathfcn f, double x, char * msg) {
    errno = 0;
    double rv = f(x);
    if (errno != 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return rv;
}
