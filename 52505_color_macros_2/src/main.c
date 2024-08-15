#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MK_COLOR(r, g, b) (((uint8_t) (b)) << 16) | (((uint8_t) (g)) << 8) | (((uint8_t) (r)) << 0)
#define GET_RED(color) ((((uint32_t) (color)) & (255 << 0)) >> 0)
#define GET_GREEN(color) ((((uint32_t) (color)) & (255 << 8)) >> 8)
#define GET_BLUE(color) ((((uint32_t) (color)) & (255 << 16)) >> 16)

int main (void) {

    uint32_t color = MK_COLOR(128, 0, 255);

    fprintf(stdout, "{\n");
    fprintf(stdout, "   r: 0x%hx\n", GET_RED(color));
    fprintf(stdout, "   g: 0x%hx\n", GET_GREEN(color));
    fprintf(stdout, "   b: 0x%hx\n", GET_BLUE(color));
    fprintf(stdout, "}\n");
    return EXIT_SUCCESS;
}
