#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MK_COLOR(r, g, b) (((uint8_t) (b)) << 16) | (((uint8_t) (g)) << 8) | (((uint8_t) (r)) << 0)

int main (void) {

    uint32_t color = MK_COLOR(128, 0, 255);

    fprintf(stdout, "{\n");
    fprintf(stdout, "   r: 0x%hx\n", (color & (255 << 0)) >> 0);
    fprintf(stdout, "   g: 0x%hx\n", (color & (255 << 8)) >> 8);
    fprintf(stdout, "   b: 0x%hx\n", (color & (255 << 16)) >> 16);
    fprintf(stdout, "}\n");
    return EXIT_SUCCESS;
}
