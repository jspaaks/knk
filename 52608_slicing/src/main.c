#include <stdio.h>
#include <stdlib.h>

unsigned int slice (unsigned int i, int from, int width) {
    int shift = from + 1 - width;
    unsigned int ones = ~0;
    unsigned int mask = ~(ones << width);
    return (i >> shift) & mask;
}

int main (void) {
    unsigned int i = 0xffff;
    int from = 15;
    int width = 4;
    fprintf(stdout, "slice(i=%d, from=%d, width=%d): %d\n", i, from, width, slice(i, from, width));
    return EXIT_SUCCESS;
}

//      76543210
// 0x01 00000001 1
// 0x02 00000010 2
// 0x04 00000100 4
// 0x08 00001000 8
// 0x10 00010000 16
// 0x20 00100000 32
// 0x40 01000000 64
// 0x80 10000000 128
