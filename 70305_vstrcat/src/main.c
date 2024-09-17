#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);
char * vstrcat (const char *, ...);

char * vstrcat (const char * first, ...) {
    size_t nbytes = strlen(first);
    va_list ap;
    va_start(ap, first);
    while (true) {
        char * arg = va_arg(ap, char *);
        if (arg == nullptr) {
            // (char *) nullptr means varargs sequence ends
            break;
        }
        nbytes += strlen(arg);
    }
    va_end(ap);

    char * rv = malloc(nbytes + 1);
    if (rv == nullptr) {
        return nullptr;
    }
    strcat(rv, first);
    va_start(ap, first);
    while (true) {
        char * arg = va_arg(ap, char *);
        if (arg == nullptr) {
            // (char *) nullptr means varargs sequence ends
            break;
        }
        strcat(rv, arg);
    }
    va_end(ap);
    return rv;
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

    char * s = vstrcat("Hel", "lo,", " wo", "rld", ".", (char *) nullptr);
    if (s == nullptr) {
        fprintf(stderr, "Error during call to function 'vstrcat', aborting.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%s\n", s);

    free(s);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate vstrcat function.\n",
            exename);
}
