#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t swap_bytes (uint16_t i) {
    uint16_t lb = (i & (255 << 8)) >> 8;
    uint16_t hb = (i & (255 << 0)) << 8;
    return hb | lb;
}

int main (void) {
    fprintf(stdout, "Enter a hexadecimal number (up to four digits): 0x");
    uint16_t h;
    scanf("%4hx", &h);
    fprintf(stdout, "Byte swap 0x%04hX: \n", h);
    fprintf(stdout, "0x%04hX\n", swap_bytes(h));

    return EXIT_SUCCESS;
}
