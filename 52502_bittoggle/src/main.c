#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void printbits (uint8_t v, char (*buf)[8]) {
    for (size_t i = 0; i < 8; ++i) {
        (*buf)[7 - i] = v & (1 << i) ? '1' : '0';
    }
}

void toggle (uint8_t i, uint8_t ibit) {
    assert(ibit < 8 && "Didn't expect ibit values larger than 7.");

    char bits[8] = {};
    printbits(i, &bits);
    fprintf(stdout, "i = %d (0b%s)\n", i, bits);

    uint8_t b = 1 << ibit;
    i = (b & ~i) | (~b & i);

    fprintf(stdout, " -- toggled bit %d\n", ibit);
    printbits(i, &bits);
    fprintf(stdout, " -- i = %d (0b%s)\n\n", i, bits);
}

int main (void) {
    toggle(255, 7);
    toggle(127, 6);
    toggle(63, 5);
    toggle(31, 4);
    toggle(15, 3);
    toggle(7, 2);
    toggle(3, 1);
    toggle(1, 0);
    toggle(0, 7);
    return EXIT_SUCCESS;
}
