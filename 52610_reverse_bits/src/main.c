#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t reverse_bits (uint8_t n) {
    uint8_t r = 0;
    uint8_t mask = 0;
    for (size_t i = 0; i < 8; ++i) {
        mask = 1 << (7 - i);
        r += (n & mask) >> (7 - i) << i;
    }
    return r;
}

int main (void) {
    uint8_t i;
    i = 1;
    fprintf(stdout, "reverting bits of 8-bit unsigned integer %d\n", i);
    fprintf(stdout, " -- %d\n\n", reverse_bits(i));

    i = 5;
    fprintf(stdout, "reverting bits of 8-bit unsigned integer %d\n", i);
    fprintf(stdout, " -- %d\n\n", reverse_bits(i));

    i = 15;
    fprintf(stdout, "reverting bits of 8-bit unsigned integer %d\n", i);
    fprintf(stdout, " -- %d\n\n", reverse_bits(i));

    i = 128;
    fprintf(stdout, "reverting bits of 8-bit unsigned integer %d\n", i);
    fprintf(stdout, " -- %d\n\n", reverse_bits(i));

    return EXIT_SUCCESS;
}
