#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE *);

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
    long int value = strtol(p, &p, 10);
    fprintf(stdout, "Parsed as base-10 integer %ld %s parsing errors.\n", value, *p == '\0' ? "without" : "with");

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo STR";
    fprintf(stream,
            "Usage: %s\n"
            "    Demonstrate parsing of a string STR that contains an integer number.\n",
            exename);
}
