#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);
void display (FILE *, size_t, ...);

void display (FILE * stream, size_t n, ...) {
    va_list ap;
    va_start(ap, n);
    for (size_t i = 0; i < n; ++i) {
        char * s = va_arg(ap, char *);
        fprintf(stream, "%s%s", s, i == n - 1 ? "\n" : " ");
    }
    va_end(ap);
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

    display(stdout, 1, "aaa");
    display(stdout, 2, "bbb", "cccc");
    display(stdout, 3, "dddd", "eee", "ff");
    display(stdout, 4, "Special", "Agent", "Dale", "Cooper");

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate a function for printing a variable number of strings.\n",
            exename);
}
