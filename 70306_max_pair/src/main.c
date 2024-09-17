#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n;
    char * s;
} Pair;

void show_usage (FILE *);
char * max_pair (size_t, ...);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    char * s = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners", 210, "All in the Family", 86,
                        "The Sopranos");
    fprintf(stdout, "And the winner is... '%s'!\n", s);

    return EXIT_SUCCESS;
}

char * max_pair (size_t npairs, ...) {
    va_list ap;
    va_start(ap, npairs);
    Pair largest = {
        .n = INT_MIN,
        .s = "",
    };
    for (size_t i = 0; i < npairs; ++i) {
        Pair current = {
            .n = va_arg(ap, int),
            .s = va_arg(ap, char *),
        };
        if (current.n > largest.n) {
            largest = current;
        }
    }
    va_end(ap);
    return largest.s;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "    Demo the max_pair function.\n",
            exename);
}
