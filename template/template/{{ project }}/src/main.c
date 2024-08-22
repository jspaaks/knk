#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char * argv[]) {
    fprintf(stdout, "-- test compile definitions\n");
#ifndef DEBUG
    fprintf(stdout, "   DEBUG compile definition has not been defined.\n");
#else
    fprintf(stdout, "   DEBUG compile definition has been defined.\n");
#endif
    fprintf(stdout, "\n");


    fprintf(stdout, "-- test whether math library was linked\n");
    fprintf(stdout, "   sqrt(144) = %f\n", sqrt(144));
    fprintf(stdout, "\n");


    fprintf(stdout, "-- test c2x / c23 features\n");
    constexpr int n = 5;
    int arr[n] = {0, 1, 2, 3, 4};
    fprintf(stdout, "   ");
    for (size_t i = 0; i < n; i++) {
        fprintf(stdout, "%d%s", arr[i], i < n - 1 ? " " : "\n");
    }
    fprintf(stdout, "\n");

    return EXIT_SUCCESS;
}
