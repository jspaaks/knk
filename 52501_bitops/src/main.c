#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void a (void) {
    uint8_t i = 8; // b00001000
    uint8_t j = 9; // b00001001
    fprintf(stdout, "a\n");
    fprintf(stdout, " -- i = %d;\n", i);
    fprintf(stdout, " -- j = %d;\n", j);
    fprintf(stdout, " -- i >> 1 + j >> 1: %d\n", i >> 1 + j >> 1);
    fprintf(stdout, " -- i >> (1 + j) >> 1: %d\n", i >> (1 + j) >> 1);
}

void b (void) {
    uint8_t i = 1; // b00000001
    fprintf(stdout, "b\n");
    fprintf(stdout, " -- i = %d;\n", i);
    fprintf(stdout, " -- i & ~i: %d\n", i & ~i);
}

void c (void) {
    uint8_t i = 2; // b00000010
    uint8_t j = 1; // b00000001
    uint8_t k = 0; // b00000000
    fprintf(stdout, "c\n");
    fprintf(stdout, " -- i = %d;\n", i);
    fprintf(stdout, " -- j = %d;\n", j);
    fprintf(stdout, " -- k = %d;\n", k);
    fprintf(stdout, " -- ~i & j ^ k: %d\n", ~i & j ^ k);
    fprintf(stdout, " -- (~i & j) ^ k: %d\n", (~i & j) ^ k);
}

void d (void) {
    uint8_t i = 7; // b00000111
    uint8_t j = 8; // b00001000
    uint8_t k = 9; // b00001001
    fprintf(stdout, "d\n");
    fprintf(stdout, " -- i = %d;\n", i);
    fprintf(stdout, " -- j = %d;\n", j);
    fprintf(stdout, " -- k = %d;\n", k);
    fprintf(stdout, " -- i ^ j & k: %d\n", i ^ j & k);
    fprintf(stdout, " -- i ^ (j & k): %d\n", i ^ (j & k));
}

int main (void) {
    a();
    b();
    c();
    d();
    return EXIT_SUCCESS;
}
