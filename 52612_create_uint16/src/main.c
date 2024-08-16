#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t create_uint16 (uint8_t hi, uint8_t lo) {
    return lo | ((uint16_t) hi) << 8;
}

int main (void) {
    uint8_t hi = 0xf0;
    uint8_t lo = 0x0f;
    uint16_t result = create_uint16(hi, lo);
    fprintf(stdout, "Concatenating 0x%02hX and 0x%02hX\n", hi, lo);
    fprintf(stdout, " -- 0x%02hX%02hX\n", (result & 0xff00) >> 8, result & 0x00ff);
    return EXIT_SUCCESS;
}
