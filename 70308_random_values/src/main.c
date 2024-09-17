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

    const int arr[4] = { 7, 11, 15, 19 };

    srand(time(nullptr));
    size_t i = rand() % 4;
    int n = arr[i];
    fprintf(stdout, "Randomly assigned n = %d.\n", n);

    return EXIT_SUCCESS;
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Randomly assign one of 7, 11, 15, 19 to a variable n.\n"
            "   Note that the program uses time in seconds to seed the pseudo\n"
            "   random number generator, so allow at least one second between\n"
            "   calls, otherwise you'll get the same number (deterministically,\n"
            "   not randomly).\n",
            exename);
}
