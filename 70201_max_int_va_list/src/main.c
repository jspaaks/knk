#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_int (int, ...);
void show_usage (FILE * stream);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Largest int in sequence is: %d.\n", max_int(124, 56, 735, 687, 3145, 24, 56, 0));

    return EXIT_SUCCESS;
}

int max_int (int first, ...) {
    va_list ap;
    va_start(ap, first);

    int current = first;
    int largest = first;

    while (current != 0) {
        current = va_arg(ap, int);
        if (current > largest) {
            largest = current;
        }
    }
    va_end(ap);
    return largest;
}

void show_usage (FILE * stream) {
    char * exename = "max_int";
    fprintf(stream,
            "Usage: %s\n"
            "    Demo variable number of function arguments.\n",
            exename);
}
