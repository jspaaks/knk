#include <stdio.h>
#include <stdlib.h>

int main (void) {
    fprintf(stdout, "First way, using ternary:\n");
    for (int widget = 0; widget < 4; ++widget) {
        fprintf(stdout, "%d %s\n", widget, widget != 1 ? "widgets" : "widget");
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "Second way, using string precision:\n");
    for (int widget = 0; widget < 4; ++widget) {
        fprintf(stdout, "%d %.*s\n", widget, (widget != 1) + 6, "widgets");
    }
    return EXIT_SUCCESS;
}
