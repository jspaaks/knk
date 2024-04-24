#include <stdio.h>
#include <stdlib.h>

int main (void) {
    char s[] = "Hsjodi", *p;
    for (p = s; *p; p++) {
        --*p;
    }
    puts(s);
    return EXIT_SUCCESS;
}
