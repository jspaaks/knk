#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

static char * msg = "Program to convert a complex number from Cartesian coordinates to polar.";

void show_usage (FILE *);
double prompt (char *);

double prompt (char * s) {
    constexpr size_t cap = 1024;
    char buf[cap];
    int nread;
    char ch;
    double d;
    fprintf(stdout, "%s", s);
    fgets(buf, cap, stdin);
    nread = sscanf(buf, "%lf%c", &d, &ch);
    if (nread != 2 || ch != '\n') {
        fprintf(stderr, " -- Error reading from STDIN. Aborting.\n");
        exit(EXIT_FAILURE);
    }
    return d;
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

    fprintf(stdout, "%s\n", msg);
    double rpart = prompt(" -- Enter the real part of the complex number: ");
    double ipart = prompt(" -- Enter the imaginary part of the complex number: ");
    double magn = sqrt(rpart * rpart + ipart * ipart);
    double arg;
    if (rpart <= 0) {
        arg = PI + atanf(ipart / rpart);
    } else if (rpart > 0 && ipart <= 0) {
        arg = 2 * PI + atanf(ipart / rpart);
    } else if (rpart > 0 && ipart > 0) {
        arg = atanf(ipart / rpart);
    }

    // change the direction and origin so it aligns with compass
    arg = fmod(2 * PI - arg + PI / 2, 2 * PI);

    fprintf(stdout, "Complex number is:\n");
    fprintf(stdout, "%g %c %gi (Cartesian).\n", rpart, ipart < 0 ? '-' : '+', fabs(ipart));
    fprintf(stdout, "(%g, %g°) (polar).\n", magn, 360 * arg / 2 / PI);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "convert";
    fprintf(stream, "Usage: %s\n    %s\n", exename, msg);
}
