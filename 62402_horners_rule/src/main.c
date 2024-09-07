#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double brute_force (double *, size_t, double, FILE *);
double brute_force_fma (double *, size_t, double, FILE *);
double horners_rule_fma (double *, size_t, double, FILE *);
size_t read_coefficients (char *, double *, size_t);
void show_equation (double *, size_t, FILE *);

void show_equation (double * a, size_t n, FILE * stream) {
    for (size_t i = 0; i < n - 2; ++i) {
        fprintf(stream, "%fx^%zu + ", a[i], n - 1 - i);
    }
    fprintf(stream, "%fx + %f\n", a[n - 2], a[n - 1]);
}

double brute_force (double * a, size_t n, double x, FILE * stream) {
    double y = 0;
    for (size_t i = 0; i < n; ++i) {
        y += a[i] * pow(x, n - 1 - i);
    }
    fprintf(stream, " \u2726 brute force        : %f\n", y);
    return y;
}

double brute_force_fma (double * a, size_t n, double x, FILE * stream) {
    double y = 0;
    for (size_t i = 0; i < n; ++i) {
        y = fma(a[i], pow(x, n - 1 - i), y);
    }
    fprintf(stream, " \u2726 brute force (fma)  : %f\n", y);
    return y;
}

double horners_rule_fma (double * a, size_t n, double x, FILE * stream) {
    double y = a[0];
    for (size_t i = 1; i < n; ++i) {
        y = fma(y, x, a[i]);
    }
    fprintf(stream, " \u2726 horner's rule (fma): %f\n", y);
    return y;
}

size_t read_coefficients (char * filename, double * buf, size_t bufcap) {
    FILE * fp = fopen(filename, "r");
    if (fp == nullptr) {
        fprintf(stderr, "Error opening file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    size_t i = 0;
    while (true) {
        if (i >= bufcap) {
            fprintf(stderr, "Buffer overflow.\n");
            exit(EXIT_FAILURE);
        }
        int nread = fscanf(fp, " %lf", &buf[i]);
        if (nread == EOF && ferror(fp)) {
            fprintf(stderr, "Error reading data from file '%s': %s.\n", filename, strerror(errno));
            errno = 0;
            exit(EXIT_FAILURE);
        }
        if (nread == EOF && feof(fp)) {
            break;
        }
        i++;
    }
    int status = fclose(fp);
    if (status == EOF) {
        fprintf(stderr, "Error closing file '%s': %s.\n", filename, strerror(errno));
        errno = 0;
        exit(EXIT_FAILURE);
    }
    return i;
}

int main (int argc, char * argv[]) {

    char * exename = argv[0];
    if (argc != 3) {
        fprintf(stderr,
                "Usage: %s FILENAME X\n"
                "Read number and value of coefficients from FILENAME and calculate\n"
                "the value of the corresponding polynomial at X using different\n"
                "methods.\n",
                exename);
        exit(EXIT_FAILURE);
    }

    constexpr size_t cap = 128;
    double coefs[cap] = {};
    size_t n = read_coefficients(argv[1], &coefs[0], cap);
    double x;
    sscanf(argv[2], " %lf", &x);

    show_equation(coefs, n, stdout);
    brute_force(coefs, n, x, stdout);
    brute_force_fma(coefs, n, x, stdout);
    horners_rule_fma(coefs, n, x, stdout);

    return EXIT_SUCCESS;
}
