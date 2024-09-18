#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    constexpr size_t nformats = 3;
    char * fmts[nformats] = {
        "%A, %B %d, %Y  %I:%M%P",
        "%a, %d %b %y  %H:%M",
        "%m/%d/%y %l:%M:%S %p",
    };
    constexpr size_t cap = 100;
    char buf[cap] = {};

    time_t t = time(nullptr);
    struct tm now = {};
    localtime_r(&t, &now);
    for (size_t i = 0; i < nformats; ++i) {
        strftime(&buf[0], cap, fmts[i], &now);
        fprintf(stdout, "%s\n", &buf[0]);
    }

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "now";
    fprintf(stream,
            "Usage: %s\n"
            "    Display the current time in a few formats.\n",
            exename);
}
