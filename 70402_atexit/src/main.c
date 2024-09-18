#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);

void f1 (void);
void f2 (void);

void f1 (void) {
    fprintf(stdout, "That's all, ");
}

void f2 (void) {
    fprintf(stdout, "folks!\n");
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

    atexit(f2);
    atexit(f1);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate usage of atexit function.\n",
            exename);
}
