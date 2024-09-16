#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_int (int n, ...);
void show_usage (FILE * stream);

int main () {

    fprintf(stdout, "Largest int in sequence is: %d.\n", max_int(7, 124, 56, 735, 687, 3145, 24, 56));

    return EXIT_SUCCESS;
}

int max_int (int n, ...) {
    va_list ap;
    int i, current, largest;
    va_start(ap, n);
    largest = va_arg(ap, int);
    for (i = 1; i < n; i++) {
        current = va_arg(ap, int);
        if (current > largest)
            largest = current;
    }
    va_end(ap);
    return largest;
}

void show_usage (FILE * stream) {
    char * exename = "max_int";
    fprintf(stream, "Usage: %s\n", exename);
}

