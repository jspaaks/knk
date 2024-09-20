#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

void show_usage (FILE * stream) {
    char * exename = "quadratic";
    fprintf(stream,
            "Usage: %s\n"
            "    Program that prompts the user for coefficients of a quadratic\n"
            "    function ax^2 + bx + c = 0, then determines its root(s).\n",
            exename);
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    double a;
    double b;
    double c;
    constexpr size_t cap = 1024;
    char buf[cap];
    int nread;
    char ch;

    fprintf(stdout, "Program for finding the roots of a quadratic function ax^2 + bx + c = 0\n");
    fprintf(stdout, " -- Enter a value for coefficient a: ");
    fgets(buf, cap, stdin);
    nread = sscanf(buf, "%lf%c", &a, &ch);
    if (nread != 2 || ch != '\n') goto defer;

    fprintf(stdout, " -- Enter a value for coefficient b: ");
    fgets(buf, cap, stdin);
    nread = sscanf(buf, "%lf%c", &b, &ch);
    if (nread != 2 || ch != '\n') goto defer;

    fprintf(stdout, " -- Enter a value for coefficient c: ");
    fgets(buf, cap, stdin);
    nread = sscanf(buf, "%lf%c", &c, &ch);
    if (nread != 2 || ch != '\n') goto defer;

    fprintf(stdout, " -- a = %lf, b = %lf, c = %lf\n", a, b, c);

    double discriminant = pow(b, 2) - 4 * a * c;
    double denominator = 2 * a;
    double complex csqrt_of_discriminant = csqrt(discriminant);

    if (discriminant < 0) {
        double complex root0 = (-b - csqrt_of_discriminant) / denominator;
        double complex root1 = (-b + csqrt_of_discriminant) / denominator;
        double root0_r = creal(root0);
        double root0_i = cimag(root0);
        double root1_r = creal(root1);
        double root1_i = cimag(root1);
        fprintf(stdout, " -- Two roots exist: %g %c %gi and %g %c %gi\n", root0_r, root0_i < 0 ? '-' : '+',
                fabs(root0_i), root1_r, root1_i < 0 ? '-' : '+', fabs(root1_i));
    } else if (discriminant == 0) {
        double root = (-b - creal(csqrt_of_discriminant)) / denominator;
        fprintf(stdout, " -- Only one root exists: %f\n", root);
    } else {
        double root0 = (-b - creal(csqrt_of_discriminant)) / denominator;
        double root1 = (-b + creal(csqrt_of_discriminant)) / denominator;
        fprintf(stdout, " -- Two roots exist: %f and %f\n", root0, root1);
    }
    return EXIT_SUCCESS;

defer:
    fprintf(stderr, " -- Error reading from STDIN. Aborting.\n");
    exit(EXIT_FAILURE);
}
