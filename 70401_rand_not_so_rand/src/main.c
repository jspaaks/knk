#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_usage (FILE *);
void print_least_significant_bit_1 (const size_t, const size_t);
void print_least_significant_bit_2 (const size_t, const size_t);

int main (int argc, char * argv[]) {

    if (argc == 2 && (strncmp(argv[1], "--help", 7) == 0 || strncmp(argv[1], "-h", 3) == 0)) {
        show_usage(stdout);
        exit(EXIT_SUCCESS);
    }

    if (argc != 1) {
        show_usage(stderr);
        exit(EXIT_FAILURE);
    }

    srand(time(nullptr));

    constexpr size_t nrows = 10;
    constexpr size_t ncols = 100;

    print_least_significant_bit_1(nrows, ncols);
    print_least_significant_bit_2(nrows, ncols);

    return EXIT_SUCCESS;
}

void print_least_significant_bit_1 (const size_t nrows, const size_t ncols) {
    bool lsb = false;
    fprintf(stdout,
            "Method 1: Printing %zu x %zu values of rand()'s least significant bit (x means 1, ' ' means 0):\n\n",
            nrows, ncols);

    for (size_t irow = 0; irow < nrows; ++irow) {
        for (size_t icol = 0; icol < ncols; ++icol) {
            lsb = rand() & 1;
            fprintf(stdout, "%lc", lsb == 1 ? 'x' : ' ');
        }
        fprintf(stdout, "\n");
    }
}

void print_least_significant_bit_2 (const size_t nrows, const size_t ncols) {
    bool lsb = false;
    fprintf(stdout,
            "\nMethod 2: Printing %zu x %zu values of rand()'s least significant bit (x means 1, ' ' means 0):\n\n",
            nrows, ncols);

    for (size_t irow = 0; irow < nrows; ++irow) {
        for (size_t icol = 0; icol < ncols; ++icol) {
            lsb = (rand() >> 8) & 1;
            fprintf(stdout, "%lc", lsb == 1 ? 'x' : ' ');
        }
        fprintf(stdout, "\n");
    }
}

void show_usage (FILE * stream) {
    char * exename = "demo";
    fprintf(stream,
            "Usage: %s\n"
            "   Demonstrate different patterns in usage of rand function (on some systems).\n",
            exename);
}
