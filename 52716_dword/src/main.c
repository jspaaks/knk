#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    typedef union {
        struct {
            uint32_t eax, ebx, ecx, edx;
        } dwords;

        struct {
            uint16_t ax : 16;
            uint16_t : 16;
            uint16_t bx : 16;
            uint16_t : 16;
            uint16_t cx : 16;
            uint16_t : 16;
            uint16_t dx : 16;
            uint16_t : 16;
        } words;

        struct {
            uint8_t al : 8;
            uint8_t ah : 8;
            uint16_t : 16;
            uint8_t bl : 8;
            uint8_t bh : 8;
            uint16_t : 16;
            uint8_t cl : 8;
            uint8_t ch : 8;
            uint16_t : 16;
            uint8_t dl : 8;
            uint8_t dh : 8;
            uint16_t : 16;
        } bytes;
    } Registers;

    Registers regs = {
        .dwords = {
            .eax = 0xfedcba98,
            .ebx = 0x76543210,
            .ecx = 0x01234567,
            .edx = 0x89abcdef,
        }
    };

    fprintf(stdout, "Different views on the same bits through type unions:\n");

    // -----

    fprintf(stdout, " -- EAX = 0x%02hX%02hX%02hX%02hX\n", (regs.dwords.eax & 0xff000000) >> 24,
            (regs.dwords.eax & 0x00ff0000) >> 16, (regs.dwords.eax & 0x0000ff00) >> 8, regs.dwords.eax & 0x000000ff);
    fprintf(stdout, " --  AX =     0x%02hX%02hX\n", (regs.words.ax & 0xff00) >> 8, regs.words.ax & 0x00ff);
    fprintf(stdout, " --  AH =     0x%02hX\n", regs.bytes.ah);
    fprintf(stdout, " --  AL =       0x%02hX\n\n", regs.bytes.al);

    // -----

    fprintf(stdout, " -- EBX = 0x%02hX%02hX%02hX%02hX\n", (regs.dwords.ebx & 0xff000000) >> 24,
            (regs.dwords.ebx & 0x00ff0000) >> 16, (regs.dwords.ebx & 0x0000ff00) >> 8, regs.dwords.ebx & 0x000000ff);
    fprintf(stdout, " --  BX =     0x%02hX%02hX\n", (regs.words.bx & 0xff00) >> 8, regs.words.bx & 0x00ff);
    fprintf(stdout, " --  BH =     0x%02hX\n", regs.bytes.bh);
    fprintf(stdout, " --  BL =       0x%02hX\n\n", regs.bytes.bl);

    // -----

    fprintf(stdout, " -- ECX = 0x%02hX%02hX%02hX%02hX\n", (regs.dwords.ecx & 0xff000000) >> 24,
            (regs.dwords.ecx & 0x00ff0000) >> 16, (regs.dwords.ecx & 0x0000ff00) >> 8, regs.dwords.ecx & 0x000000ff);
    fprintf(stdout, " --  CX =     0x%02hX%02hX\n", (regs.words.cx & 0xff00) >> 8, regs.words.cx & 0x00ff);
    fprintf(stdout, " --  CH =     0x%02hX\n", regs.bytes.ch);
    fprintf(stdout, " --  CL =       0x%02hX\n\n", regs.bytes.cl);

    // -----

    fprintf(stdout, " -- EDX = 0x%02hX%02hX%02hX%02hX\n", (regs.dwords.edx & 0xff000000) >> 24,
            (regs.dwords.edx & 0x00ff0000) >> 16, (regs.dwords.edx & 0x0000ff00) >> 8, regs.dwords.edx & 0x000000ff);
    fprintf(stdout, " --  DX =     0x%02hX%02hX\n", (regs.words.dx & 0xff00) >> 8, regs.words.dx & 0x00ff);
    fprintf(stdout, " --  DH =     0x%02hX\n", regs.bytes.dh);
    fprintf(stdout, " --  DL =       0x%02hX\n\n", regs.bytes.dl);

    return EXIT_SUCCESS;
}
