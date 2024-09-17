#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);
double unit_random (void);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * p = argv[1];
    while (*p != '\0') {
        if (isspace(*p)) {
            p++;
        } else if (*p == '-') {
            fprintf(stderr, "Argument N should be a positive integer. Aborting.\n");
            exit(EXIT_FAILURE);
        } else if (isdigit(*p)) {
            break;
        } else {
            p++;
        }
    }

    srand(time(nullptr));
    char * endptr = argv[1];
    errno = 0;
    unsigned long n = strtoul(argv[1], &endptr, 10);
    if (*endptr != '\0' || errno != 0) {
        fprintf(stderr, "Error parsing '%s' as a positive integer number, aborting.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Here %s %zu unit random %s:\n", n == 1 ? "is" : "are", n, n == 1 ? "number" : "numbers");

    for (size_t i = 0; i < n; ++i) {
        fprintf(stdout, "%f\n", unit_random());
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s N\n"
            "   Draw a sequence of N unit random numbers.\n"
            "   Note that the program uses time in seconds to seed the pseudo\n"
            "   random number generator, so allow at least one second between\n"
            "   calls, otherwise you'll get the same sequence of random numbers\n"
            "   (deterministically, not randomly).\n",
            exename);
}

double unit_random (void) {
    return (double) rand() / RAND_MAX;
}
