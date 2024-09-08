#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usage (FILE * stream);

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s STR N\n"
            "   Replace the last N characters of STR with exclamation points.\n",
            exename);
}

void exclaim (char * s, size_t n) {
    size_t cap = strlen(s);
    char fill = '!';
    if (cap >= n) {
        memset(s + cap - n, fill, n);
    } else {
        fprintf(stderr, "String is too short to write %zu chars.\n", n);
        exit(EXIT_FAILURE);
    }
}

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 3) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * s = argv[1];
    unsigned int n;
    sscanf(argv[2], " %u", &n);

    fprintf(stdout, "before: %s\n", s);
    exclaim(s, n);
    fprintf(stdout, "after : %s\n", s);

    return EXIT_SUCCESS;
}
