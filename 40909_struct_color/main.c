#include <stdio.h>
#include <stdbool.h>
#include "color.h"

int main (void) {
    {
        fprintf(stdout, "clipping, printing\n");
        const struct color c = new(128, 0, 2550);
        print(c);
    }

    {
        fprintf(stdout, "\nequality\n");
        const struct color c1 = new(128, 0, 0);
        const struct color c2 = new(128, 0, 230);
        fprintf(stdout, "c1:     ");
        print(c1);
        fprintf(stdout, "c2:     ");
        print(c2);
        fprintf(stdout, "c1 is %sequal to c2\n", is_equal(c1, c2) ? "" : "not ");
    }

    {
        fprintf(stdout, "\nequality\n");
        const struct color c1 = new(128, 0, 0);
        const struct color c2 = new(128, 0, 0);
        fprintf(stdout, "c1:     ");
        print(c1);
        fprintf(stdout, "c2:     ");
        print(c2);
        fprintf(stdout, "c1 is %sequal to c2\n", is_equal(c1, c2) ? "" : "not ");
    }

    {

        fprintf(stdout, "\nbrightening\n");
        const struct color c1 = new(0, 0, 0);
        fprintf(stdout, "before: ");
        print(c1);
        const struct color c2 = brighten(c1);
        fprintf(stdout, "after : ");
        print(c2);
    }

    {

        fprintf(stdout, "\nbrightening\n");
        const struct color c1 = new(178, 200, 2);
        fprintf(stdout, "before: ");
        print(c1);
        const struct color c2 = brighten(c1);
        fprintf(stdout, "after : ");
        print(c2);
    }

    {
        fprintf(stdout, "\ndarkening\n");
        const struct color c1 = new(10, 100, 0);
        fprintf(stdout, "before: ");
        print(c1);
        const struct color c2 = darken(c1);
        fprintf(stdout, "after : ");
        print(c2);
    }

    return 0;
}
