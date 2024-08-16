#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void printbits (const uint8_t v, char (*buf)[9]) {
    for (size_t i = 0; i < 8; ++i) {
        (*buf)[7 - i] = v & (1 << i) ? '1' : '0';
    }
    (*buf)[8] = '\0';
}

int main (void) {
    char buf[9] = {};

    fprintf(stdout, "       n              n - 1         n & (n - 1)  \n");
    fprintf(stdout, "---------------  ---------------  ---------------\n");
    uint8_t n = 255;
    do {
        printbits(n, &buf);
        fprintf(stdout, "%3d  0b%s  ", n, &buf[0]);
        printbits(n - 1, &buf);
        fprintf(stdout, "%3d  0b%s  ", n - 1, &buf[0]);
        printbits(n & (n - 1), &buf);
        fprintf(stdout, "%3d  0b%s\n", n & (n - 1), &buf[0]);
        n--;
    } while (n != 255);
    return EXIT_SUCCESS;
}
