#include <stdio.h>
#include <stdlib.h>

int count_ones (unsigned char ch) {
return \
    ((ch & 1) >> 0) +  \
    ((ch & 2) >> 1) +  \
    ((ch & 4) >> 2) +  \
    ((ch & 8) >> 3) +  \
    ((ch & 16) >> 4) + \
    ((ch & 32) >> 5) + \
    ((ch & 64) >> 6) + \
    ((ch & 128) >> 7);  
}

int main (void) {
    unsigned char c = 5;
    fprintf(stdout, "%d has %d ones in its binary representation.\n", c, count_ones(c));
    return EXIT_SUCCESS;
}
