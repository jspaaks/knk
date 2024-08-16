#include <stdio.h>
#include <stdlib.h>

int main (void) {
    struct {
        unsigned int flag : 1;
    } s;

    s.flag = 1;
    fprintf(stdout, "%d\n", s.flag);
    return EXIT_SUCCESS;
}
