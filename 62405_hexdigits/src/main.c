#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int parse_hex_str (char *);
void show_usage (FILE *);

long int parse_hex_str (char * s) {
    char * p = s;
    long unsigned int buf;

    bool ispositive = true;
    if (*p == '-') {
        ispositive = false;
        p++;
    }

    if (!isxdigit(*p)) {
        fprintf(stderr, "Character '%c' could not be parsed as hexadecimal.\n", *p);
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    sscanf(p, "%lx", &buf);
    if (buf > LONG_MAX) {
        fprintf(stderr, "Integer overflow.\n");
        exit(EXIT_FAILURE);
    }

    return (ispositive ? 1 : -1) * (long int) buf;
}

void show_usage (FILE * stream) {
    char * exename = "checkhex";
    fprintf(stream,
            "Usage: %s STR\n"
            "    Check whether string STR can be interpreted as hexadecimal\n"
            "    number, and if so, print it as base 10.\n",
            exename);
}

int main (int argc, char * argv[]) {

    if (argc != 2) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    if (strncmp(argv[1], "-h", 3) == 0 || strncmp(argv[1], "--help", 7) == 0) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    char * input = argv[1];
    long int number = parse_hex_str(input);
    fprintf(stdout, "Base 10 equivalent of '%s' is '%ld'.\n", input, number);

    return EXIT_SUCCESS;
}
