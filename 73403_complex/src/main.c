#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

static const char * msg = "Program to convert a complex number from Cartesian to polar coordinates.";

void show_usage (FILE *);
double prompt (char *);

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

    double magn = prompt(" -- Enter the magnitude of the complex number: ");
    double theta_deg = prompt(" -- Enter the argument of the complex number in degrees: ");

    double theta = 2 * PI * (90 - theta_deg) / 360;

    double rpart = magn * cosf(theta);
    double ipart = magn * sinf(theta);

    fprintf(stdout, "%g %c %gi\n", rpart, ipart < 0 ? '-' : '+', fabs(ipart));

    return EXIT_SUCCESS;
}

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
        fprintf(stderr, "Error parsing the complex number.\n");
        exit(EXIT_FAILURE);
    };
    return d;
}

void show_usage (FILE * stream) {
    char * exename = "convert";
    fprintf(stream, "Usage: %s\n    %s\n", exename, msg);
}
