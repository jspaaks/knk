#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t rotate_left (const uint32_t i, const uint8_t nshift) {
    uint32_t mask = 0xffffffff << (32 - nshift);
    uint32_t half = (mask & i) >> (32 - nshift);
    uint32_t and_half = (~mask & i) << nshift;
    return half | and_half;
}

uint32_t rotate_right (const uint32_t i, const uint8_t nshift) {
    uint32_t mask = 0xffffffff >> (32 - nshift);
    uint32_t half = (mask & i) << (32 - nshift);
    uint32_t and_half = (~mask & i) >> nshift;
    return half | and_half;
}

int main (void) {
    uint32_t i;
    uint8_t nshift = 8;
    uint32_t shifted;

    i = 0x12345678;
    fprintf(stdout, "i: 0x%04hX%04hX\n", i >> 16, i & 0xffff);
    fprintf(stdout, " -- shifting left %d positions\n", nshift);
    shifted = rotate_left(i, nshift);
    fprintf(stdout, " -- 0x%04hX%04hX\n", shifted >> 16, shifted & 0xffff);

    i = 0x89abcdef;
    fprintf(stdout, "i: 0x%04hX%04hX\n", i >> 16, i & 0xffff);
    fprintf(stdout, " -- shifting right %d positions\n", nshift);
    shifted = rotate_right(i, nshift);
    fprintf(stdout, " -- 0x%04hX%04hX\n", shifted >> 16, shifted & 0xffff);

    return EXIT_SUCCESS;
}
