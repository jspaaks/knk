#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void printbits (const uint8_t v, char (*buf)[9]) {
    for (size_t i = 0; i < 8; ++i) {
        (*buf)[7 - i] = v & (1 << i) ? '1' : '0';
    }
    (*buf)[8] = '\0';
}

void toggle (const uint8_t ibit, uint8_t i) {
    assert(ibit < 8 && "Didn't expect ibit values larger than 7.");

    char bits[9] = {};
    printbits(i, &bits);
    fprintf(stdout, "i = %d (0b%s)\n", i, bits);

    uint8_t b = 1 << ibit;
    i = (b & ~i) | (~b & i);

    fprintf(stdout, " -- toggled bit %d\n", ibit);
    printbits(i, &bits);
    fprintf(stdout, " -- i = %d (0b%s)\n\n", i, bits);
}

int main (void) {
    toggle(7, 255);
    toggle(6, 127);
    toggle(5, 63);
    toggle(4, 31);
    toggle(3, 15);
    toggle(2, 7);
    toggle(1, 3);
    toggle(0, 1);
    toggle(7, 0);
    return EXIT_SUCCESS;
}
