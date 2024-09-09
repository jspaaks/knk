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
    if (discriminant < 0) {
        fprintf(stdout, " -- Discriminant < 0: roots are complex.\n");
        return EXIT_SUCCESS;
    }

    double sqrt_of_discriminant = sqrt(discriminant);
    double denominator = 2 * a;

    if (discriminant == 0) {
        fprintf(stdout, " -- Only one root exists: %f\n", (-b - sqrt_of_discriminant) / denominator);
    } else {
        fprintf(stdout, " -- Two roots exist: %f and %f\n", (-b - sqrt_of_discriminant) / denominator,
                (-b + sqrt_of_discriminant) / denominator);
    }
    return EXIT_SUCCESS;

defer:
    fprintf(stderr, " -- Error reading from STDIN. Aborting.\n");
    exit(EXIT_FAILURE);
}
