#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

void show_usage (FILE *);
void uncomplex (complex double, double *, double *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Program to print the roots of unity.\n");

    char * nptr = argv[1];
    char * endptr = argv[1];
    long unsigned n = strtoul(nptr, &endptr, 10);
    if (*nptr == '\0' || *endptr != '\0') {
        fprintf(stderr, "Error parsing number from '%s', aborting.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "k     z\n");
    for (size_t k = 0; k < n; ++k) {
        double complex exponent = 2 * PI * I * k / n;
        double complex z = cexp(exponent);
        {
            double rpart;
            double ipart;
            uncomplex(z, &rpart, &ipart);
            fprintf(stdout, "%-7zu% g %c %g\n", k, rpart, ipart < 0 ? '-' : '+', fabs(ipart));
        }
    }

    return EXIT_SUCCESS;
}

void uncomplex (complex double cd, double * realpart, double * imagpart) {
    *realpart = creal(cd);
    *imagpart = cimag(cd);
}

void show_usage (FILE * stream) {
    char * exename = "roots";
    fprintf(stream, "Usage: %s N\n    Program to print the roots 0..N-1 of unity.\n", exename);
}
